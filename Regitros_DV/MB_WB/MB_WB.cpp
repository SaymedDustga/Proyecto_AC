#include "ME_WB.h"


me_wb::me_wb(sc_module_name nm) : sc_module(nm) {

  SC_METHOD(operation);
  sensitive << clkIn;
}

void me_wb::operation() {
  for(int i = 0; i < 2; i++){
    memo_Out[i].write(memo_In[i].read());
  }

  dir_Out.write(dir_In.read());
  Wb_MemtoRegOut.write(Wb_MemtoRegIn.read()); 
  Wb_no_ideaOut.write(Wb_no_ideaIn.read());
}

