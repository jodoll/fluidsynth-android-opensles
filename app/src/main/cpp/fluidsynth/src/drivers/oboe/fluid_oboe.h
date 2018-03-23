
#ifndef FLUIDSYNTH_ANDROID_OPENSLES_FLUID_OBOEDRIVER_H
#define FLUIDSYNTH_ANDROID_OPENSLES_FLUID_OBOEDRIVER_H

#ifdef __cplusplus
class OboeDriver {
public:
    OboeDriver(fluid_synth_t * synth);
    void start();
    ~OboeDriver();

private:
    fluid_synth_t *synth;
};

struct OboeDriverWrapper {
    char *name;
    OboeDriver *driver;
};

#endif //__cplusplus

#endif //FLUIDSYNTH_ANDROID_OPENSLES_FLUID_OBOEDRIVER_H
