#include "fluid_oboe_synthesizer.h"

OboeSynthesizer::OboeSynthesizer(_fluid_synth_t *synth) {
    this->fluidSynth = synth;
}

OboeSynthesizer::~OboeSynthesizer() {
    this->fluidSynth = nullptr;
}
