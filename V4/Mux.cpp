#include "Mux.h"


Mux::Mux(sc_module_name nm) : sc_module(nm) {
  SC_METHOD(operation);
  sensitive << aIn << bIn << sIn;
  //std:: cout << "\nmux" << endl;
}

/**
 * según lo que seleccione la entrada de selección.
 * 
 * Es decir:
 * Si los bits de selección en decimal son 0, entonces seleccionará la primera entrada de datos.
 * Si los bits de selección en decimal son 1, entonces seleccionará la segunda entrada de datos.
 * Si los bits de selección en decimal son 2, entonces seleccionará la tercera entrada de datos.
 * ... y así sucesivamente (con el límite de bits de selección).
 * 
 * Y al "seleccionar" una entrada de datos, el mux deja pasar el valor de esa entrada de datos.
 * Lo que hace el mux es sencillamente dejar pasar una de las entradas de datos
 * Sin embargo, con bits no podemos "dejar pasar" una entrada de datos en particular, lo que podemos
 * hacer es a través de operaciones binarias hacer que la salida sea exactamente igual a
 * la entrada de datos seleccionada.
 */
void Mux::operation() {
  /*bool a = !s0In.read();
  bool b = d0In.read() and a;
  bool c = d1In.read() and s0In.read();
  fOut.write(b or c);*/


  if(sIn.read()) cOut.write(bIn.read());
  else cOut.write(aIn.read());
}

Mux::~Mux() {}
