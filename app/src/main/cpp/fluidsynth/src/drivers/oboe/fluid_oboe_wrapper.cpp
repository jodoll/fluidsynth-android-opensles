#include <fluidsynth.h>
#include <stdexcept>
#include "fluid_oboe_wrapper.h"
#include "fluid_oboe_driver.h"

#define AS_OBOE_WRAPPER(a) (reinterpret_cast<OboeDriverWrapper*>(a))
#define AS_FLUID_AUDIO_DRIVER(a)   (reinterpret_cast<fluid_audio_driver_t*>(a))


fluid_audio_driver_t *new_fluid_oboe_audio_driver(fluid_settings_t *settings,
                                                  fluid_synth_t *synth);
fluid_audio_driver_t *new_fluid_oboe_audio_driver2(fluid_settings_t *settings,
                                                   fluid_audio_func_t func, void *data);
void delete_fluid_oboe_audio_driver(fluid_audio_driver_t *self);
void fluid_oboe_audio_driver_settings(fluid_settings_t *settings);

fluid_audio_driver_t *new_fluid_oboe_audio_driver(fluid_settings_t *settings, fluid_synth_t *fluidSynth) {
    char *name = (char *) "oboe";
    OboeSynthesizer *synthesizer = new OboeSynthesizer(fluidSynth);
    OboeDriver *driver = new OboeDriver(synthesizer);

    OboeDriverWrapper *wrapper = new OboeDriverWrapper();
    wrapper->name = name;
    wrapper->driver = driver;
    wrapper->synthesizer = synthesizer;

    driver->start();

    return AS_FLUID_AUDIO_DRIVER(wrapper);
}

fluid_audio_driver_t *new_fluid_oboe_audio_driver2(fluid_settings_t *settings, fluid_audio_func_t func, void *data) {
    //Unsupported mode
    throw std::logic_error("constructor2 mode is not yet implemented and thus not supported");
}

void delete_fluid_oboe_audio_driver(fluid_audio_driver_t *self) {
    OboeDriverWrapper *wrapper = AS_OBOE_WRAPPER(self);

    delete wrapper->driver;
    wrapper->driver = NULL;
    delete wrapper->synthesizer;
    wrapper->synthesizer = NULL;
    delete wrapper;
}

void fluid_oboe_audio_driver_settings(fluid_settings_t *settings) {
    //Nothing for now
}