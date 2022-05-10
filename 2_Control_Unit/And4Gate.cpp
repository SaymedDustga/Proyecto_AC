#include "And4Gate.h"

And4Gate::And4Gate(sc_module_name moduleName) : sc_module(moduleName) {
  SC_METHOD(operation); 
  sensitive << aIn << bIn << cIn << dIn;
}

And4Gate::~And4Gate() {}

void And4Gate::operation() {

  eOut.write(aIn.read() and bIn.read() and cIn.read() and dIn.read());

}