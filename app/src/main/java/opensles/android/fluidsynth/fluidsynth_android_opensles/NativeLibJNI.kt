package opensles.android.fluidsynth.fluidsynth_android_opensles

class NativeLibJNI {
    external fun init(sf2path: String)
    external fun noteOn(key: Int, velocity: Int)
    external fun noteOff(key: Int)
    external fun programChange(channel: Int, programNumber: Int) : Boolean
    /**
     * Set synth output gain value.
     * @param gain Gain value (function clamps value to the range 0.0 to 10.0)
     */
    external fun setGain(gain: Float)
    external fun destroy()
}