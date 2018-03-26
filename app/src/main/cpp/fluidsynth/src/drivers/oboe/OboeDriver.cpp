#include <fluidsynth.h>
#include <stdexcept>
#include <oboe/AudioStreamBuilder.h>
#include "OboeDriver.h"

OboeDriver::OboeDriver(OboeSynthesizer *synth, OboeAudioSettings *audioSettings) {
    this->synthesizer = synth;
    this->audioSettings = audioSettings;
}

void OboeDriver::open() {
    openStream();
    adjustSynthesizerSampleRate();
    audioStream->requestStart();
}

void OboeDriver::openStream() {
    oboe::AudioStreamBuilder builder = oboe::AudioStreamBuilder();

    builder.setDirection(oboe::Direction::Output);
    builder.setPerformanceMode(oboe::PerformanceMode::LowLatency);

    builder.setFormat(audioSettings->audioFormat);
    builder.setSampleRate(audioSettings->sampleRateHz);
    builder.setChannelCount(audioSettings->channelCount);
    builder.setBufferCapacityInFrames(audioSettings->bufferSizeFrames);

    builder.setCallback(this);

    if (oboe::Result::OK != builder.openStream(&audioStream)) {
        fluid_log(FLUID_ERR, "OboeError: Couldn't open AudioStream");
    }
}


void OboeDriver::adjustSynthesizerSampleRate() {
    int32_t actualSampleRateHz = audioStream->getSampleRate();
    if (audioSettings->sampleRateHz != actualSampleRateHz) {
        fluid_log(FLUID_WARN, "Actual sample rate differs from requested rate, trying to adjust synthesizers rate from %d to %d", audioSettings->sampleRateHz, actualSampleRateHz);
        audioSettings->sampleRateHz = actualSampleRateHz;
        synthesizer->setSampleRate(actualSampleRateHz);
    }
}

oboe::DataCallbackResult OboeDriver::onAudioReady(oboe::AudioStream *oboeStream, void *audioData, int32_t numFrames) {
    synthesizer->fillBuffer(static_cast<int16_t *>(audioData), numFrames);
    return oboe::DataCallbackResult::Continue;
}

void OboeDriver::onErrorBeforeClose(oboe::AudioStream *oboeStream, oboe::Result error) {
    fluid_log(FLUID_ERR, "OboeError while trying to close AudioStream: %d", error);
}

void OboeDriver::onErrorAfterClose(oboe::AudioStream *oboeStream, oboe::Result error) {
    fluid_log(FLUID_ERR, "OboeError after closing AudioStream: %d", error);
}

void OboeDriver::closeStream() {
    if (audioStream == nullptr) return;

    audioStream->stop();
    audioStream->close();
    delete audioStream;
    audioStream = nullptr;
}

OboeDriver::~OboeDriver() {
    closeStream();
    synthesizer = nullptr;
    audioSettings = nullptr;
}
