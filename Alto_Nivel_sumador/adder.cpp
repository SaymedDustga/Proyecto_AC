#include "adder.h"


Adder::Adder(sc_module_name nm) : sc_module(nm) {
  SC_METHOD(operation);
  sensitive << clkIn;
}

void Adder::operation() {

  int sum = number_1In.read();
  int sum_2 =  number_2In.read(); 
  resultOut.write(sum + sum_2);

}
