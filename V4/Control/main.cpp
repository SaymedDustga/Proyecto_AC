#include "Unidad_Control.h"
#include "Testbench.h"
/*
Daniel Venegas V28391873
*/

int sc_main(int argv, char* argc[]) {
  sc_time period(10,SC_NS);
  sc_time delay(10,SC_NS);

  sc_clock clock("clock", period, 0.5, delay, true);

  Unidad_Control Unidad_Control("Unidad_Control");
  Testbench tb("tb");


  sc_signal<bool> clkIn;
  sc_signal<cs_unit<2>> Ex_ALUSrc_1, Ex_ALUOp_1;
  sc_signal<bool> Men_MemWrite_1, Men_MemRead_1, Men_Branch_1;
  sc_signal<bool> Wb_MemtoReg_1, Wb_no_idea_1 ;
  sc_signal<bool> Read_write ;


  sc_signal<sc_uint<32>> dir_1;




  Unidad_Control.Ex_ALUSrcOut(Ex_ALUSrc_1), Unidad_Control.Ex_ALUOpOut(Ex_ALUOp_1);
  Unidad_Control.Men_MemWriteOut(Men_MemWrite_1), Unidad_Control.Men_MemReadOut(Men_MemRead_1), Unidad_Control.Men_BranchOut(Men_Branch_1);
  Unidad_Control.Wb_MemtoRegOut(Wb_MemtoReg_1), Unidad_Control.Wb_no_ideaOut(Wb_no_idea_1) ;
  Unidad_Control.read_writeOut(Read_write);

  Unidad_Control.dir_In(dir_1)
/*
  tb.read_writeIn(Read_write);
  tb.Ex_ALUSrcIn(Ex_ALUSrc_2), tb.Ex_ALUOpIn(Ex_ALUOp_2);
  tb.Men_MemWriteIn(Men_MemWrite_2), tb.Men_MemReadIn(Men_MemRead_2), tb.Men_BranchIn(Men_Branch_2);
  tb.Wb_MemtoRegIn(Wb_MemtoReg_2), tb.Wb_no_ideaIn(Wb_no_idea_2) ;

  tb.dir_Out(dir_1)

*/


  Unidad_Control.clkIn(clock);
  tb.clkIn(clock);

  sc_start();

  return 0;
}
