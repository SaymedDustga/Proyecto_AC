#include "adder.h"
#include "Testbench.h"
/*
Daniel Venegas V28391873
*/

int sc_main(int argv, char* argc[]) {
  sc_time period(10,SC_NS);
  sc_time delay(10,SC_NS);

  sc_clock clock("clock", period, 0.5, delay, true);

  Adder adder("adder");
  Testbench tb("tb");

  sc_signal<sc_int<32>> add_1, add_2, result;

  adder.number_1In(add_1);
  adder.number_2In(add_2);
  adder.resultOut(result);
  adder.clkIn(clock);



  tb.numberIn(result);
  tb.send_number_1Out(add_1);
  tb.send_number_2Out(add_2);

  tb.clkIn(clock);

  sc_start();

  return 0;
}
