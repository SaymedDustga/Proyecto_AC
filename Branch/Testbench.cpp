#include "Testbench.h"
#include <iomanip>
using namespace std;

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clkIn;
  dont_initialize();
}
void Testbench::print() {
  cout << setw(6) << sc_time_stamp();
  cout << setw(4) << "";
  cout << setw(4) << numberIn.read().to_string() ;
  cout << setw(4) << "";
  cout << setw(4) << past_jumpOut.read();
  cout << setw(4) << "";
  cout << setw(4) << jump_resultIn.read();
  cout << setw(4) << "";
  cout << setw(4) << clkIn.read();
  cout << setw(4) << "";
  cout << "\n";
}


void Testbench::test() {
  cout << "Tiempo    numberIn    past_jumpOut    click\n";
  cout << "----------------------------------------------------------------------------------\n";



  int a[] = { 4, 4, 4, 4,100,1,16};
  

  for (int j = 0; j < 7; j++) {
    numberIn.write(a[j]);
    past_jumpOut.write(a[j] % 2);
    wait();
    print();    
    cout << "---------------------------------------------------------------------------------\n";
  }
  sc_stop();
}
