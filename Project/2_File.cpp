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
  if (weIn.read() and rwIn.read()){
    memory[rwIn.read()] = wIn.read(); 
    std:: cout << "\nEn el registro: " << rwIn.read() << " he guardado: " << wIn.read() << endl;
  }
}

void File::write() {

  aOut.write(memory[raIn.read()]);
  bOut.write(memory[rbIn.read()]);     

}
