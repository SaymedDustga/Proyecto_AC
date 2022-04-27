#include "EX_MEN.h"


ex_men::ex_men(sc_module_name nm) : sc_module(nm) {

  SC_METHOD(operation);
  sensitive << clkIn;
}

void ex_men::operation() {
  for(int i = 0; i < 4; i++){
    memo_Out[i].write(memo_In[i].read());
  }
  dir_Out.write(dir_In.read());
  alu_to_brachOut.write(alu_to_brachIn.read());


 
  Men_MemWriteOut.write(Men_MemWriteIn.read()); 
  Men_MemReadOut.write(Men_MemReadIn.read()); 
  Men_BranchOut.write(Men_BranchIn.read());
  Wb_MemtoRegOut.write(Wb_MemtoRegIn.read()); 
  Wb_no_ideaOut.write(Wb_no_ideaIn.read());
}
