#ifndef FLUIDSYNTH_ANDROID_OPENSLES_FLUID_OBOE_WRAPPER_H
#define FLUIDSYNTH_ANDROID_OPENSLES_FLUID_OBOE_WRAPPER_H

#include <fluidsynth.h>
#include "OboeDriver.h"

#ifdef __cplusplus

struct OboeDriverWrapper {
    char *name;
    OboeDriver *driver;
    OboeSynthesizer *synthesizer;
    OboeAudioSettings *audioSettings;

    ~OboeDriverWrapper() {
        delete driver;
        driver = NULL;
        delete synthesizer;
        synthesizer = NULL;
        delete audioSettings;
        audioSettings = NULL;
    }
};

#endif

#ifdef __cplusplus
extern "C" {
#endif
fluid_audio_driver_t *new_fluid_oboe_audio_driver(fluid_settings_t *settings,
                                                  fluid_synth_t *synth);
fluid_audio_driver_t *new_fluid_oboe_audio_driver2(fluid_settings_t *settings,
                                                   fluid_audio_func_t func, void *data);
void delete_fluid_oboe_audio_driver(fluid_audio_driver_t *self);
void fluid_oboe_audio_driver_settings(fluid_settings_t *settings);

#ifdef __cplusplus
};
#endif
#endif //FLUIDSYNTH_ANDROID_OPENSLES_FLUID_OBOE_WRAPPER_H
