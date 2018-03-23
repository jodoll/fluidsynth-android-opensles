#include <fluidsynth.h>
#include "fluid_oboe_synthesizer.h"

OboeSynthesizer::OboeSynthesizer(_fluid_synth_t *synth) {
    this->fluidSynth = synth;
}

void OboeSynthesizer::fillBuffer(int16_t *buffer, int len) {
    fluid_synth_write_s16(this->fluidSynth, len, buffer, 0, 2, buffer, 1, 2);
}

OboeSynthesizer::~OboeSynthesizer() {
    this->fluidSynth = nullptr;
}
