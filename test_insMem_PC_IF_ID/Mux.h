#ifndef MUX_H
#define MUX_H

#include <iostream>

#include <systemc.h>


/**
 * El mux recibe 2 tipos de entradas:
 * - Entradas de selección: s0In
 * - Entradas de datos: d0In, d1In
 * Si n es la cantidad de entradas de selección,
 * entonces 2^n entradas de datos serán recibidas.
 * 
 * Para éste mux, n = 1, por lo que recibirá 1 entrada de selección
 * y 2^1 entradas de datos.
 */
class Mux: public sc_module {
public:
  sc_in<bool> sIn;
  sc_in<sc_int<32>> aIn, bIn;
  sc_out<sc_int<32>> cOut;

  SC_CTOR(Mux);
  ~Mux();

private:
  void operation();
};

#endif