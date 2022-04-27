#ifndef NOTGATE_H
#define NOTGATE_H

#include <systemc.h>


class NotGate : public sc_module {
public:
  sc_in<bool> aIn;
  sc_out<bool> bOut;

  SC_CTOR(NotGate);

private:
  void operation();
};

#endif