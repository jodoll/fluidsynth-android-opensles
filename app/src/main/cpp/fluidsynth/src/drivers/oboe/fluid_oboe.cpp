#include <fluidsynth.h>
#include <stdexcept>
#include "fluid_oboe.h"



OboeDriver::OboeDriver(fluid_synth_t *synth) {
    this->synth = synth;
}

void OboeDriver::start() {

}

OboeDriver::~OboeDriver() {
    this->synth = NULL;
}
