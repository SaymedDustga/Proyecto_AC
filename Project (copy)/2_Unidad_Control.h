#ifndef UNIDAD_CONTROL
#define UNIDAD_CONTROL

#include <systemc.h>


class Unidad_Control: public sc_module {
public:

  //sc_in<bool> clkIn; 
  sc_out<sc_uint<2>> Ex_ALUOpOut;
  sc_out<bool> Ex_ALUSrcOut;
  sc_out<bool> Mem_MemWriteOut, Mem_MemReadOut, Mem_BranchOut, read_writeOut;
  sc_out<bool> Wb_MemtoRegOut, Wb_RegWriteOut ;//ni idea para sirve sea esa señal de control

  sc_in<sc_int<8>> dir_In;


  SC_CTOR(Unidad_Control);

private:
  void operation();
};

#endif
