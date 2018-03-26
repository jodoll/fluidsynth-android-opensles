#include <jni.h>
#include <fluidsynth.h>
#include <fluid_settings_constants.h>
#include <oboe/OboeDriver.h>

fluid_settings_t *settings;
fluid_synth_t *synth;
fluid_audio_driver_t *audioDriver;

extern "C"
JNIEXPORT void JNICALL Java_opensles_android_fluidsynth_fluidsynth_1android_1opensles_NativeLibJNI_init(
        JNIEnv *env,
        jobject /* this */,
        jstring sf2path) {
    // Init settings
    settings = new_fluid_settings();
    fluid_settings_setstr(settings, KEY_DRIVER, DRIVER_NAME_OBOE);
    fluid_settings_setint(settings, KEY_PERIOD_SIZE, 64);
    fluid_settings_setnum(settings, KEY_SAMPLE_RATE, 48000);

    synth = new_fluid_synth(settings);

    // Init soundfont
    const char *nativeSf2Path = env->GetStringUTFChars(sf2path, NULL);
    fluid_synth_sfload(synth, nativeSf2Path, true);
    env->ReleaseStringUTFChars(sf2path, nativeSf2Path);

    audioDriver = new_fluid_audio_driver(settings, synth);
}

extern "C"
JNIEXPORT void JNICALL Java_opensles_android_fluidsynth_fluidsynth_1android_1opensles_NativeLibJNI_noteOn(
        JNIEnv *env,
        jobject /* this */,
        jint key,
        jint velocity) {
    fluid_synth_noteon(synth, 0, key, velocity);
}

extern "C"
JNIEXPORT void JNICALL Java_opensles_android_fluidsynth_fluidsynth_1android_1opensles_NativeLibJNI_noteOff(
        JNIEnv *env,
        jobject /* this */,
        jint key) {
    fluid_synth_noteoff(synth, 0, key);
}

extern "C"
JNIEXPORT jboolean JNICALL Java_opensles_android_fluidsynth_fluidsynth_1android_1opensles_NativeLibJNI_programChange(
        JNIEnv *env,
        jobject /* this */,
        jint channel,
        jint programNumber) {
    return (jboolean) (FLUID_OK == fluid_synth_program_change(synth, (int) channel, (int) programNumber));
}

/**
 * Set synth output gain value.
 * @param gain Gain value (function clamps value to the range 0.0 to 10.0)
 */
extern "C"
JNIEXPORT void JNICALL Java_opensles_android_fluidsynth_fluidsynth_1android_1opensles_NativeLibJNI_setGain(
        JNIEnv *env,
        jobject /* this */,
        jfloat gain) {
    fluid_synth_set_gain(synth, (float) gain);
}

extern "C"
JNIEXPORT void JNICALL Java_opensles_android_fluidsynth_fluidsynth_1android_1opensles_NativeLibJNI_destroy(
        JNIEnv *env,
        jobject /* this */) {
    delete_fluid_audio_driver(audioDriver);
    audioDriver = NULL;
    delete_fluid_synth(synth);
    synth = NULL;
    delete_fluid_settings(settings);
    settings = NULL;
}
