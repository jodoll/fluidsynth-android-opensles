#include <fluidsynth.h>
#include <stdexcept>
#include <oboe/AudioStreamBuilder.h>
#include "fluid_oboe_driver.h"

OboeDriver::OboeDriver(OboeSynthesizer *synth) {
    this->synthesizer = synth;
}

void OboeDriver::start() {
    this->openStream();
    this->audioStream->requestStart();
}

void OboeDriver::openStream() {
    oboe::AudioStreamBuilder builder = oboe::AudioStreamBuilder();

    builder.setDirection(oboe::Direction::Output);
    builder.setPerformanceMode(oboe::PerformanceMode::LowLatency);

    builder.setFormat(audioFormat);
    builder.setSampleRate(sampleRateHz);
    builder.setChannelCount(channelCount);
    builder.setBufferCapacityInFrames(bufferSizeFrames);

    builder.setCallback(this);

    if (oboe::Result::OK != builder.openStream(&this->audioStream)) {
        fluid_log(FLUID_ERR, "OboeError: Couldn't open AudioStream");
    }
}

oboe::DataCallbackResult OboeDriver::onAudioReady(oboe::AudioStream *oboeStream, void *audioData, int32_t numFrames) {
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

    this->audioStream->stop();
    this->audioStream->close();
    delete this->audioStream;
    this->audioStream = nullptr;
}

OboeDriver::~OboeDriver() {
    closeStream();
    this->synthesizer = nullptr;
}
