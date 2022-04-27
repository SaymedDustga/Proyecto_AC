#include "ME_WB.h"
#include "Testbench.h"
/*
Daniel Venegas V28391873
*/

int sc_main(int argv, char* argc[]) {
  sc_time period(10,SC_NS);
  sc_time delay(10,SC_NS);

  sc_clock clock("clock", period, 0.5, delay, true);

  me_wb me_wb("me_wb");
  Testbench tb("tb");


  sc_signal<bool> clkIn;

  sc_signal<bool> Wb_MemtoReg_1, Wb_no_idea_1 ;
  sc_signal<sc_int<32>> memo_1[2];
  sc_signal<sc_uint<32>> dir_1;


  sc_signal<bool> Wb_MemtoReg_2, Wb_no_idea_2 ;

  sc_signal<sc_int<32>> memo_2[2];
  sc_signal<sc_uint<32>> dir_2;



  me_wb.Wb_MemtoRegIn(Wb_MemtoReg_1), me_wb.Wb_no_ideaIn(Wb_no_idea_1) ;
  me_wb.Wb_MemtoRegOut(Wb_MemtoReg_2), me_wb.Wb_no_ideaOut(Wb_no_idea_2) ;

  for(int i = 0; i< 2; i++){
    me_wb.memo_In[i](memo_1[i]);
  } 

  me_wb.dir_In(dir_1);
  

  for(int i = 0; i< 2; i++){
    me_wb.memo_Out[i](memo_2[i]);
  } 
  
  me_wb.dir_Out(dir_2);
  



  tb.Wb_MemtoRegIn(Wb_MemtoReg_2), tb.Wb_no_ideaIn(Wb_no_idea_2) ;
  tb.Wb_MemtoRegOut(Wb_MemtoReg_1), tb.Wb_no_ideaOut(Wb_no_idea_1) ;

  for(int i = 0; i< 2; i++){
    tb.memo_In[i](memo_2[i]);
  } 

  tb.dir_In(dir_2);
  

  for(int i = 0; i< 2; i++){
    tb.memo_Out[i](memo_1[i]);
  } 

  tb.dir_Out(dir_1);
  



  me_wb.clkIn(clock);

  tb.clkIn(clock);

  sc_start();

  return 0;
}
