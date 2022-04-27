#include "adder.h"


Adder::Adder(sc_module_name nm) : sc_module(nm) , number_1In("number_1In"), number_2In("number_2In"), resultOut("resultOut"), clk("clk") {
  SC_METHOD(operation);
  sensitive << clk;
  dont_initialize(); 
  sum_aux = 0;
  std:: cout << "\nadder" << endl;
}

void Adder::operation() {


  int sum = number_1In.read() + sum_aux;
 // std:: cout << "\nMi ultimo valor en la suma es: " << sum << endl;
  int sum_2 =  number_2In.read();
  std:: cout << "\nMi ultimo valor es: " << sum + sum_2 << endl;
  resultOut.write(sum + sum_2);

}
