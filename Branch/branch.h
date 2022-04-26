#ifndef MUX_H
#define MUX_H

#include <systemc.h>


class branch: public sc_module {
public:

  sc_in<sc_uint<16>> addressIn;
  sc_in<bool> clkIn, jumpIn;
  sc_out<bool> answerOut;

  SC_CTOR(branch);

private:
  int menu[2][30];
  int th;
  void operation();
};

#endif
