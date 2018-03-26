#ifndef FLUIDSYNTH_ANDROID_OPENSLES_FLUID_OBOEDRIVER_H
#define FLUIDSYNTH_ANDROID_OPENSLES_FLUID_OBOEDRIVER_H

#include <oboe/AudioStreamCallback.h>
#include <oboe/AudioStream.h>
#include "OboeSynthesizer.h"

#ifdef __cplusplus

class OboeDriver : oboe::AudioStreamCallback {
public:
    OboeDriver(OboeSynthesizer *synthesizer);

    void open();

    ~OboeDriver();

private:
    oboe::DataCallbackResult onAudioReady(oboe::AudioStream *oboeStream, void *audioData, int32_t numFrames) override;

private:
    int channelCount = 2;
    int32_t bufferSizeFrames = 64;
    int32_t sampleRateHz = 44100;
    oboe::AudioFormat audioFormat = oboe::AudioFormat::I16;

    OboeSynthesizer *synthesizer = nullptr;
    oboe::AudioStream *audioStream = nullptr;

    void openStream();

    void closeStream();

    void onErrorBeforeClose(oboe::AudioStream *oboeStream, oboe::Result error) override;

    void onErrorAfterClose(oboe::AudioStream *oboeStream, oboe::Result error) override;
};

#endif //__cplusplus

#endif //FLUIDSYNTH_ANDROID_OPENSLES_FLUID_OBOEDRIVER_H
