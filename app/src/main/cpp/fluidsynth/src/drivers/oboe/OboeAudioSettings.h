
//
// Created by Johannes Doll on 3/26/18.
// Copyright (c) 2018 fluidmobile GmbH. All rights reserved.
//

#ifndef FLUIDSYNTH_ANDROID_OPENSLES_OBOEAUDIOSETTINGS_H
#define FLUIDSYNTH_ANDROID_OPENSLES_OBOEAUDIOSETTINGS_H

#include <oboe/Definitions.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <fluidsynth.h>

constexpr int OBOE_DEFAULT_BUFFER_SIZE = 512;
constexpr int OBOE_MIN_BUFFER_SIZE = 16; //Chosen by guess
constexpr int OBOE_MAX_BUFFER_SIZE = 1024000; //Chosen by guess

constexpr int OBOE_DEFAULT_BURST_SIZE = 192; //Chosen by guess (4ms at 48000Hz)
constexpr int OBOE_MIN_BURST_SIZE = 2; //Chosen by guess
constexpr int OBOE_MAX_BURST_SIZE = OBOE_MAX_BUFFER_SIZE; //Chosen by guess

constexpr int OBOE_UNDEFINED_SETTING = -1;
#ifdef __cplusplus
};
#endif

#ifdef __cplusplus

class OboeAudioSettings {
public:
    static void registerCustomSettingsAttributes(fluid_settings_t *settings);

    OboeAudioSettings(fluid_settings_t *settings);

    OboeAudioSettings(int channelCount, int32_t bufferSizeFrames, int32_t sampleRateHz, oboe::AudioFormat audioFormat);

    int channelCount = 2;
    int32_t bufferSizeFrames = OBOE_UNDEFINED_SETTING;
    int32_t burstSizeFrames = OBOE_UNDEFINED_SETTING;
    int32_t sampleRateHz = OBOE_UNDEFINED_SETTING;
    oboe::AudioFormat audioFormat = oboe::AudioFormat::Unspecified;
};

#endif //__cplusplus

#endif //FLUIDSYNTH_ANDROID_OPENSLES_OBOEAUDIOSETTINGS_H
