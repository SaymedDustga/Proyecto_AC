#ifndef MUX_H
#define MUX_H

#include <systemc.h>

#include "AndGate.h"
#include "OrGate.h"
#include "NotGate.h"


// Un mux de 2 entradas (de solo bits) que usaremos para crear un mux de 2 entradas de 8 bits.
class _mux: public sc_module {
public:
  sc_in<bool> aIn, bIn, sIn;
  sc_out<bool> cOut;

  SC_CTOR(_mux);

private:
  sc_vector<AndGate> _ands;
  OrGate _or;
  NotGate _not;

  sc_signal<bool> sg[3];
};


#define MUX_BITS 32


/* Ésta implementación de bajo nivel es para cuando quieran usar sc_int o sc_int. Básicamente
en el constructor se hacen las conexiones entre módulos internos si es necesaria y los que
deberían conectar con el módulo padre (en éste caso Mux), quedan sueltos y hay que usar una
función para simular la conxión. */
class Mux: public sc_module {
public:
  sc_in<sc_int<MUX_BITS>> aIn, bIn;
  sc_in<bool> sIn;
  sc_out<sc_int<MUX_BITS>> cOut;

  SC_CTOR(Mux);

private:
  // En ésta función se simulará la conexión con el módulo padre.
  void assemble();

  sc_vector<_mux> muxs;
  sc_signal<bool> aSg[MUX_BITS], bSg[MUX_BITS], cSg[MUX_BITS];
};

#endif
