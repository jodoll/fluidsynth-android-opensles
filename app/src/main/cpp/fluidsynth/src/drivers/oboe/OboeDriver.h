#ifndef FLUIDSYNTH_ANDROID_OPENSLES_FLUID_OBOEDRIVER_H
#define FLUIDSYNTH_ANDROID_OPENSLES_FLUID_OBOEDRIVER_H

#include <oboe/AudioStreamCallback.h>
#include <oboe/AudioStream.h>
#include "OboeSynthesizer.h"
#include "OboeAudioSettings.h"

constexpr const char *DRIVER_NAME_OBOE = "oboe";

#ifdef __cplusplus

class OboeDriver : oboe::AudioStreamCallback {
public:
    OboeDriver(OboeSynthesizer *synthesizer, OboeAudioSettings *audioSettings);

    void open();

    ~OboeDriver();

private:
    oboe::DataCallbackResult onAudioReady(oboe::AudioStream *oboeStream, void *audioData, int32_t numFrames) override;

private:
    OboeAudioSettings *audioSettings = nullptr;
    OboeSynthesizer *synthesizer = nullptr;
    oboe::AudioStream *audioStream = nullptr;

    void openStream();

    void closeStream();

    void onErrorBeforeClose(oboe::AudioStream *oboeStream, oboe::Result error) override;

    void onErrorAfterClose(oboe::AudioStream *oboeStream, oboe::Result error) override;
};

#endif //__cplusplus

#endif //FLUIDSYNTH_ANDROID_OPENSLES_FLUID_OBOEDRIVER_H
