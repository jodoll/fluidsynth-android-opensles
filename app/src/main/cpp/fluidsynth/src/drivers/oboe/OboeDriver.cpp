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

    builder.setFormat(this->audioSettings->audioFormat);
    builder.setSampleRate(this->audioSettings->sampleRateHz);
    builder.setChannelCount(this->audioSettings->channelCount);
    builder.setBufferCapacityInFrames(this->audioSettings->bufferSizeFrames);

    builder.setCallback(this);

    if (oboe::Result::OK != builder.openStream(&this->audioStream)) {
        fluid_log(FLUID_ERR, "OboeError: Couldn't open AudioStream");
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
