#include "ID_EX.h"
#include "Testbench.h"
/*
Daniel Venegas V28391873
*/

int sc_main(int argv, char* argc[]) {
  sc_time period(10,SC_NS);
  sc_time delay(10,SC_NS);

  sc_clock clock("clock", period, 0.5, delay, true);

  id_ex id_ex("id_ex");
  Testbench tb("tb");


  sc_signal<bool> clkIn;
  sc_signal<bool> Ex_ALUSrc_1, Ex_ALUOp_1;
  sc_signal<bool> Men_MemWrite_1, Men_MemRead_1, Men_Branch_1;
  sc_signal<bool> Wb_MemtoReg_1, Wb_no_idea_1 ;
  sc_signal<sc_int<32>> memo_1[2];
  sc_signal<sc_uint<32>> dir_1[3];


  sc_signal<bool> Ex_ALUSrc_2, Ex_ALUOp_2;
  sc_signal<bool> Men_MemWrite_2, Men_MemRead_2, Men_Branch_2;
  sc_signal<bool> Wb_MemtoReg_2, Wb_no_idea_2 ;
  sc_signal<sc_int<32>> memo_2[2];
  sc_signal<sc_uint<32>> dir_2[3];




  id_ex.Ex_ALUSrcIn(Ex_ALUSrc_1), id_ex.Ex_ALUOpIn(Ex_ALUOp_1);
  id_ex.Men_MemWriteIn(Men_MemWrite_1), id_ex.Men_MemReadIn(Men_MemRead_1), id_ex.Men_BranchIn(Men_Branch_1);
  id_ex.Wb_MemtoRegIn(Wb_MemtoReg_1), id_ex.Wb_no_ideaIn(Wb_no_idea_1) ;

  id_ex.Ex_ALUSrcOut(Ex_ALUSrc_2), id_ex.Ex_ALUOpOut(Ex_ALUOp_2);
  id_ex.Men_MemWriteOut(Men_MemWrite_2), id_ex.Men_MemReadOut(Men_MemRead_2), id_ex.Men_BranchOut(Men_Branch_2);
  id_ex.Wb_MemtoRegOut(Wb_MemtoReg_2), id_ex.Wb_no_ideaOut(Wb_no_idea_2) ;
  for(int i = 0; i< 2; i++){
    id_ex.memo_In[i](memo_1[i]);
  } 
  for(int i = 0; i< 3; i++){  
    id_ex.dir_In[i](dir_1[i]);
  }

  for(int i = 0; i< 2; i++){
    id_ex.memo_Out[i](memo_2[i]);
  } 
  for(int i = 0; i< 3; i++){  
    id_ex.dir_Out[i](dir_2[i]);
  }


  tb.Ex_ALUSrcIn(Ex_ALUSrc_2), tb.Ex_ALUOpIn(Ex_ALUOp_2);
  tb.Men_MemWriteIn(Men_MemWrite_2), tb.Men_MemReadIn(Men_MemRead_2), tb.Men_BranchIn(Men_Branch_2);
  tb.Wb_MemtoRegIn(Wb_MemtoReg_2), tb.Wb_no_ideaIn(Wb_no_idea_2) ;

  tb.Ex_ALUSrcOut(Ex_ALUSrc_1), tb.Ex_ALUOpOut(Ex_ALUOp_1);
  tb.Men_MemWriteOut(Men_MemWrite_1), tb.Men_MemReadOut(Men_MemRead_1), tb.Men_BranchOut(Men_Branch_1);
  tb.Wb_MemtoRegOut(Wb_MemtoReg_1), tb.Wb_no_ideaOut(Wb_no_idea_1) ;
  for(int i = 0; i< 2; i++){
    tb.memo_In[i](memo_2[i]);
  } 
  for(int i = 0; i< 3; i++){  
    tb.dir_In[i](dir_2[i]);
  }

  for(int i = 0; i< 2; i++){
    tb.memo_Out[i](memo_1[i]);
  } 
  for(int i = 0; i< 3; i++){  
    tb.dir_Out[i](dir_1[i]);
  }



  id_ex.clkIn(clock);

  tb.clkIn(clock);

  sc_start();

  return 0;
}
