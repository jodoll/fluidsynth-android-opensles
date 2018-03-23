
#ifndef FLUIDSYNTH_ANDROID_OPENSLES_FLUID_OBOE_SYNTHESIZER_H
#define FLUIDSYNTH_ANDROID_OPENSLES_FLUID_OBOE_SYNTHESIZER_H

#ifdef __cplusplus

class OboeSynthesizer {
public:
    OboeSynthesizer(struct _fluid_synth_t *synth);

    ~OboeSynthesizer();

private:
    struct _fluid_synth_t *fluidSynth;
};

#endif

#endif //FLUIDSYNTH_ANDROID_OPENSLES_FLUID_OBOE_SYNTHESIZER_H