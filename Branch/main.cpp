#include "branch.h"
#include "Testbench.h"
/*
Daniel Venegas V28391873
*/

int sc_main(int argv, char* argc[]) {
  sc_time period(10,SC_NS);
  sc_time delay(10,SC_NS);

  sc_clock clock("clock", period, 0.5, delay, true);

  branch branch("branch");
  Testbench tb("tb");

  sc_signal<sc_uint<16>> dir ;
  sc_signal<bool> cableA, cableB;

  branch.addressIn(dir);
  branch.jumpIn(cableA);
  branch.answerOut(cableB);
  branch.clkIn(clock);



  tb.numberIn(dir);
  tb.past_jumpOut(cableA);
  tb.jump_resultIn(cableB);

  tb.clkIn(clock);

  sc_start();

  return 0;
}
