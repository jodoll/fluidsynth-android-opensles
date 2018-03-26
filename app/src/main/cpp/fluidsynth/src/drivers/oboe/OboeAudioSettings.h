
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

#ifdef __cplusplus
};
#endif

#ifdef __cplusplus

class OboeAudioSettings {

public:
    OboeAudioSettings(fluid_settings_t *settings);

    OboeAudioSettings(int channelCount, int32_t bufferSizeFrames, int32_t sampleRateHz, oboe::AudioFormat audioFormat);

    int channelCount = 2;
    int32_t bufferSizeFrames = -1;
    int32_t sampleRateHz = -1;
    oboe::AudioFormat audioFormat = oboe::AudioFormat::Unspecified;
};

#endif //__cplusplus

#endif //FLUIDSYNTH_ANDROID_OPENSLES_OBOEAUDIOSETTINGS_H
