#include "ID_EX.h"


id_ex::id_ex(sc_module_name nm) : sc_module(nm) {

  SC_METHOD(operation);
  sensitive << clkIn;
}

void id_ex::operation() {
  for(int i = 0; i < 2; i++){
    memo_Out[i].write(memo_In[i].read());
  }
  for(int i = 0; i < 3; i++){
    dir_Out[i].write(dir_In[i].read());
  }


  Ex_ALUSrcOut.write(Ex_ALUSrcIn.read());
  Ex_ALUOpOut.write(Ex_ALUOpIn.read());
  Men_MemWriteOut.write(Men_MemWriteIn.read()); 
  Men_MemReadOut.write(Men_MemReadIn.read()); 
  Men_BranchOut.write(Men_BranchIn.read());
  Wb_MemtoRegOut.write(Wb_MemtoRegIn.read()); 
  Wb_no_ideaOut.write(Wb_no_ideaIn.read());
}
