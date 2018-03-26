#include <fluid_settings_constants.h>
#include "OboeAudioSettings.h"

OboeAudioSettings::OboeAudioSettings(fluid_settings_t *settings) {
    fluid_settings_getint(settings, KEY_PERIOD_SIZE, &bufferSizeFrames);

    double sampleRate;
    fluid_settings_getnum(settings, KEY_SAMPLE_RATE, &sampleRate);
    this->sampleRateHz = (int32_t) sampleRate;

    if (fluid_settings_str_equal(settings, KEY_SAMPLE_FORMAT, SAMPLE_FORMAT_FLOAT)) {
        audioFormat = oboe::AudioFormat::Float;
    } else {
        audioFormat = oboe::AudioFormat::I16;
    }

}

OboeAudioSettings::OboeAudioSettings(int channelCount, int32_t bufferSizeFrames, int32_t sampleRateHz, oboe::AudioFormat audioFormat) {
    this->channelCount = channelCount;
    this->bufferSizeFrames = bufferSizeFrames;
    this->sampleRateHz = sampleRateHz;
    this->audioFormat = audioFormat;
}
