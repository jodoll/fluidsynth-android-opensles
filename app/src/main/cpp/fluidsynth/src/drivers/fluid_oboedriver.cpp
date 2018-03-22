#include "fluid_oboedriver.h"
#define TO_CPP(a) (reinterpret_cast<OboeDriver*>(a))
#define TO_C(a)   (reinterpret_cast<oboedriver_t*>(a))


OboeDriver::OboeDriver() {
}

int OboeDriver::getVersion() {
    return 42;
}

OboeDriver::~OboeDriver() {

}


// c compat code
oboedriver_t *oboedriver_create(){
    oboedriver_t * driver = TO_C(new OboeDriver);
    return driver;
}

int oboedriver_get_version(oboedriver_t *self){
    return TO_CPP(self)->getVersion();
}

void oboedriver_destroy(oboedriver_t *self){
    delete TO_CPP(self);
}