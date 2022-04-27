#include "EX_MEN.h"
#include "Testbench.h"
/*
Daniel Venegas V28391873
*/

int sc_main(int argv, char* argc[]) {
  sc_time period(10,SC_NS);
  sc_time delay(10,SC_NS);

  sc_clock clock("clock", period, 0.5, delay, true);

  ex_men ex_men("ex_men");
  Testbench tb("tb");




  sc_signal<bool> clkIn;

  sc_signal<bool> Wb_MemtoReg_1, Wb_no_idea_1 ;
  sc_signal<bool> Men_MemWrite_1, Men_MemRead_1, Men_Branch_1;
 
  sc_signal<sc_int<32>> memo_1[4];
  sc_signal<sc_uint<32>> dir_1;


  sc_signal<bool> Men_MemWrite_2, Men_MemRead_2, Men_Branch_2;
  sc_signal<bool> Wb_MemtoReg_2, Wb_no_idea_2 ;

  sc_signal<sc_int<32>> memo_2[4];
  sc_signal<sc_uint<32>> dir_2;

  sc_signal<bool> alu_to_brach_1, alu_to_brach_2 ;


  ex_men.alu_to_brachIn(alu_to_brach_1), ex_men.alu_to_brachOut(alu_to_brach_2);
  ex_men.Men_MemWriteIn(Men_MemWrite_1), ex_men.Men_MemReadIn(Men_MemRead_1), ex_men.Men_BranchIn(Men_Branch_1);
  ex_men.Men_MemWriteOut(Men_MemWrite_2), ex_men.Men_MemReadOut(Men_MemRead_2), ex_men.Men_BranchOut(Men_Branch_2);
  ex_men.Wb_MemtoRegIn(Wb_MemtoReg_1), ex_men.Wb_no_ideaIn(Wb_no_idea_1) ;
  ex_men.Wb_MemtoRegOut(Wb_MemtoReg_2), ex_men.Wb_no_ideaOut(Wb_no_idea_2) ;

  for(int i = 0; i< 4; i++){
    ex_men.memo_In[i](memo_1[i]);
  } 

  ex_men.dir_In(dir_1);
  

  for(int i = 0; i< 4; i++){
    ex_men.memo_Out[i](memo_2[i]);
  } 
  
  ex_men.dir_Out(dir_2);
  

  tb.alu_to_brachIn(alu_to_brach_2), tb.alu_to_brachOut(alu_to_brach_1);

  tb.Men_MemWriteOut(Men_MemWrite_1), tb.Men_MemReadOut(Men_MemRead_1), tb.Men_BranchOut(Men_Branch_1);
  tb.Men_MemWriteIn(Men_MemWrite_2), tb.Men_MemReadIn(Men_MemRead_2), tb.Men_BranchIn(Men_Branch_2);
  tb.Wb_MemtoRegIn(Wb_MemtoReg_2), tb.Wb_no_ideaIn(Wb_no_idea_2) ;
  tb.Wb_MemtoRegOut(Wb_MemtoReg_1), tb.Wb_no_ideaOut(Wb_no_idea_1) ;

  for(int i = 0; i< 4; i++){
    tb.memo_In[i](memo_2[i]);
  } 

  tb.dir_In(dir_2);
  

  for(int i = 0; i< 4; i++){
    tb.memo_Out[i](memo_1[i]);
  } 

  tb.dir_Out(dir_1);
  



  ex_men.clkIn(clock);

  tb.clkIn(clock);

  sc_start();

  return 0;
}
