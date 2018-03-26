
//
// Created by Johannes Doll on 3/26/18.
// Copyright (c) 2018 fluidmobile GmbH. All rights reserved.
//

#ifndef FLUIDSYNTH_ANDROID_OPENSLES_SETTINGS_H
#define FLUIDSYNTH_ANDROID_OPENSLES_SETTINGS_H

#ifdef __cplusplus
extern "C" {
#endif

constexpr const char *KEY_SAMPLE_RATE = "synth.sample-rate";
constexpr const char *KEY_SAMPLE_FORMAT = "audio.sample-format";
constexpr const char *KEY_PERIOD_SIZE = "audio.period-size";
constexpr const char *KEY_BUFFER_SIZE = "audio.oboe.buffer-size";
constexpr const char *KEY_BURST_SIZE = "audio.oboe.burst-size";
constexpr const char *KEY_DRIVER = "audio.driver";

constexpr const char *SAMPLE_FORMAT_FLOAT = "float";
#ifdef __cplusplus
};
#endif
#endif //FLUIDSYNTH_ANDROID_OPENSLES_SETTINGS_H
