#ifndef MEM_WB_H
#define MEM_WB_H

#include <systemc.h>


class MEM_WB : public sc_module {
public:

  sc_in<bool> clkIn;

  sc_in<bool> Wb_MemtoRegIn, Wb_RegWriteIn;

  sc_out<bool> Wb_MemtoRegOut, Wb_RegWriteOut;

  sc_vector<sc_in<sc_int<32>>> SC_NAMED(memo_In, 2);
  sc_vector<sc_out<sc_int<32>>> SC_NAMED(memo_Out, 2);

  sc_in<sc_int<8>> dir_In;
  sc_out<sc_int<8>> dir_Out;

  SC_CTOR(MEM_WB);

private:

  void operation();
};

#endif