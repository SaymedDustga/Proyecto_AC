#include "Mux.h"


_mux::_mux(sc_module_name nm) : sc_module(nm), _ands("_ands", 2), _or("_or"), _not("_not") {
  _not.aIn(sIn);
  _not.bOut(sg[0]);

  _ands[0].aIn(aIn);
  _ands[0].bIn(sg[0]);
  _ands[0].cOut(sg[1]);

  _ands[1].aIn(bIn);
  _ands[1].bIn(sIn);
  _ands[1].cOut(sg[2]);

  _or.aIn(sg[1]);
  _or.bIn(sg[2]);
  _or.cOut(cOut);
}

Mux::Mux(sc_module_name nm) : sc_module(nm), muxs("muxs", MUX_BITS) {
  for (int i = 0; i < MUX_BITS; i++) {
    muxs[i].aIn(aSg[i]);
    muxs[i].bIn(bSg[i]);
    muxs[i].cOut(cSg[i]);
    muxs[i].sIn(sIn);
  }

  SC_METHOD(assemble);
  /* Cuando hacen éste tipo de implementación, deben hacer éste método sensible a todas las
  entradas del módulo y a los signals que se supone que son la salida del módulo. */
  sensitive << aIn << bIn << sIn;
  for (int i = 0; i < MUX_BITS; i++)
    sensitive << cSg[i];
}

/* Básicamente lo que hacemos acá es escribir la salida manualmente según los valores de bits
que estén en los signals que representan la salida del módulo. */
void Mux::assemble() {
  sc_int<MUX_BITS> tmp;
  for (int i = 0; i < MUX_BITS; i++) {
    aSg[i] = aIn.read()[i];
    bSg[i] = bIn.read()[i];
    tmp[i] = cSg[i].read();
  }
  cOut.write(tmp);
}
