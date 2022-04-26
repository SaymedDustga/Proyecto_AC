#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>

#include <systemc.h>


class Testbench : public sc_module {
public:

  sc_out<sc_uint<16>> numberIn;
  sc_out<bool> past_jumpOut;
  sc_in<bool> clkIn, jump_resultIn;

  SC_CTOR(Testbench);

private:
  void print();
  void test();
};

#endif
