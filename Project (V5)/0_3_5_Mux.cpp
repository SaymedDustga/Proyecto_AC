#include "0_3_5_Mux.h"


Mux::Mux(sc_module_name nm) : sc_module(nm) {
  SC_METHOD(operation);
  sensitive << aIn << bIn << sIn;
}


 void Mux::operation() {


  if(sIn.read()) cOut.write(bIn.read());
  else cOut.write(aIn.read());
}

Mux::~Mux() {}