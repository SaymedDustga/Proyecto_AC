#include "5_MuxWB.h"


MuxWB::MuxWB(sc_module_name nm) : sc_module(nm) {
  SC_METHOD(operation);
  sensitive << aIn << bIn << sIn;
  //std:: cout << "\nmux" << endl;
}


 void MuxWB::operation() {


  if(sIn.read()) cOut.write(bIn.read());
  else cOut.write(aIn.read());
}

MuxWB::~MuxWB() {}