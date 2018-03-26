#include <fluid_settings_constants.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <fluidsynth.h>
#include <fluid_settings.h>

#ifdef __cplusplus
};
#endif

#include "OboeAudioSettings.h"

void OboeAudioSettings::registerCustomSettingsAttributes(fluid_settings_t *settings) {
    fluid_settings_register_int(settings, KEY_BUFFER_SIZE, OBOE_DEFAULT_BUFFER_SIZE, OBOE_MIN_BUFFER_SIZE, OBOE_MAX_BUFFER_SIZE,
                                FLUID_HINT_BOUNDED_BELOW);
    fluid_settings_register_int(settings, KEY_BURST_SIZE, OBOE_DEFAULT_BURST_SIZE, OBOE_MIN_BURST_SIZE, OBOE_MAX_BURST_SIZE,
                                FLUID_HINT_BOUNDED_BELOW);
}

OboeAudioSettings::OboeAudioSettings(fluid_settings_t *settings) {
    fluid_settings_getint(settings, KEY_BUFFER_SIZE, &bufferSizeFrames);
    fluid_settings_getint(settings, KEY_BURST_SIZE, &burstSizeFrames);

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
