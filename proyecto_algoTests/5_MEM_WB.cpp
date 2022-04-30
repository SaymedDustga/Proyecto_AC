#include "5_MEM_WB.h"


MEM_WB::MEM_WB(sc_module_name nm) : sc_module(nm) {

  SC_METHOD(operation);
  sensitive << clkIn.pos(); 
}

void MEM_WB::operation() {
  for(int i = 0; i < 2; i++){
    memo_Out[i].write(memo_In[i].read());
//    std:: cout << "\n\n\n\n\n\nMEMO EN WB" << memo_In[i].read() << "\n\n\n\n\n\n\n";
  }

  dir_Out.write(dir_In.read());
  Wb_MemtoRegOut.write(Wb_MemtoRegIn.read()); 
  Wb_RegWriteOut.write(Wb_RegWriteIn.read());
}

