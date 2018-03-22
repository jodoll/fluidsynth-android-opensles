
#ifndef FLUIDSYNTH_ANDROID_OPENSLES_FLUID_OBOEDRIVER_H
#define FLUIDSYNTH_ANDROID_OPENSLES_FLUID_OBOEDRIVER_H

#ifdef __cplusplus
class OboeDriver {
public:
    OboeDriver();
    int getVersion();
    ~OboeDriver();
};

#endif //__cplusplus

#ifdef __cplusplus
extern "C"{
#endif
    typedef struct t_oboedriver oboedriver_t;

    oboedriver_t *oboedriver_create();
    int oboedriver_get_version(oboedriver_t *self);
    void oboedriver_destroy(oboedriver_t *self);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //FLUIDSYNTH_ANDROID_OPENSLES_FLUID_OBOEDRIVER_H
