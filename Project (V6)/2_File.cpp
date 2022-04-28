#include "2_File.h"


File::File(sc_module_name nm) : sc_module(nm) {

  SC_METHOD(write);
  //sensitive << clkIn.neg();
  sensitive << rwIn<<raIn<<rbIn<<weIn<<wIn;
  SC_METHOD(read);
//  sensitive << clkIn.pos();
  sensitive << rwIn<<raIn<<rbIn<<weIn<<wIn;

}

void File::read() {
  memory[0] = 0;
  if (weIn.read()){
    memory[rwIn.read()] = wIn.read(); 
  }
}

void File::write() {

  aOut.write(memory[raIn.read()]);
  bOut.write(memory[rbIn.read()]);     

}
