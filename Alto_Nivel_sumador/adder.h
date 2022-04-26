#ifndef MUX_H
#define MUX_H

#include <systemc.h>


class Adder: public sc_module {
public:

  sc_in<sc_int<32>> number_1In, number_2In;
  sc_out<sc_int<32>> resultOut;
  sc_in<bool> clkIn;

  SC_CTOR(Adder);

private:
  void operation();
};

#endif
