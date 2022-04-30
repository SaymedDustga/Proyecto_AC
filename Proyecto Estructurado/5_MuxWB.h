#ifndef MUXWB_H
#define MUXWB_H

#include <iostream>

#include <systemc.h>

class MuxWB : public sc_module {
public:
  sc_in<bool> RegWriteIn;
  sc_in<sc_int<32>> aIn, bIn;
  sc_out<sc_int<32>> cOut;

  SC_CTOR(MuxWB);
  ~MuxWB();

private:
  void operation();
};

#endif