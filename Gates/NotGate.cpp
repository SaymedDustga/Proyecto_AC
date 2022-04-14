#include "NotGate.h"


NotGate::NotGate(sc_module_name mn) : sc_module(mn) {
  SC_METHOD(operation);
  sensitive << aIn;
}

void NotGate::operation() {
  bOut.write(!aIn.read());
}