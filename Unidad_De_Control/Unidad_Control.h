#ifndef Unidad_Control
#define Unidad_Control

#include <systemc.h>


class Unidad_Control: public sc_module {
public:

  sc_in<bool> clkIn; 
  sc_out<sc_uint<2>> Ex_ALUOpOut;
  sc_out<bool> Ex_ALUSrcOut, Men_MemWriteOut, Men_MemReadOut, Men_BranchOut, read_writeOutOut;
  sc_out<bool> Wb_MemtoRegOut, Wb_no_ideaOut ;//ni idea para sirve sea esa señal de control

  sc_in<sc_int<8>> dir_In;


  SC_CTOR(Unidad_Control);

private:
  void operation();
};

#endif
