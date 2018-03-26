package opensles.android.fluidsynth.fluidsynth_android_opensles

import android.content.Context
import android.media.AudioManager

class NativeLibJNI {

    companion object {
        const val DEFAULT_FRAMES_PER_BUFFER = 192
    }

    fun getDefaultOpenGlEsBurstSize(context: Context): Int {
        val myAudioMgr = context.getSystemService(Context.AUDIO_SERVICE) as AudioManager
        val framesPerBufferText: String? = myAudioMgr.getProperty(AudioManager.PROPERTY_OUTPUT_FRAMES_PER_BUFFER)
        return framesPerBufferText?.toIntOrNull() ?: DEFAULT_FRAMES_PER_BUFFER
    }

    fun init(sf2path: String, context: Context) {
        init(sf2path, getDefaultOpenGlEsBurstSize(context))
    }

    /**
     * @param sf2path path to soundfont
     * @param openGlDefaultBurstSize With OpenSL ES, the optimal framesPerBurst is not known by the native code. Use [getDefaultOpenGlEsBurstSize] to obtain it.
     */
    external fun init(sf2path: String, openGlDefaultBurstSize: Int = DEFAULT_FRAMES_PER_BUFFER)

    external fun noteOn(key: Int, velocity: Int)
    external fun noteOff(key: Int)
    external fun programChange(channel: Int, programNumber: Int): Boolean

    /**
     * Set synth output gain value.
     * @param gain Gain value (function clamps value to the range 0.0 to 10.0)
     */
    external fun setGain(gain: Float)

    external fun destroy()
}