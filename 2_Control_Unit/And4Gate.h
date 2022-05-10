#ifndef AND4_GATE_H
#define AND4_GATE_H

#include <systemc.h>

class And4Gate : public sc_module {
  public:
    sc_in<bool> aIn, cIn;  
    sc_in<bool> bIn, dIn;   
    sc_out<bool> eOut; 

    SC_CTOR(And4Gate);
    ~And4Gate(); 
  private:
    void operation();
};

#endif
