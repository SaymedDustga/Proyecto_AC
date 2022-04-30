#ifndef FILE_H
#define FILE_H

#include <systemc.h>
 const int TAM_MEMORY = 32;
class File: public sc_module {
public:

  sc_in<sc_int<8>> rwIn; 	  //dirección de registro para la variable W
  sc_in<sc_int<8>> raIn; 	  //dirección de registro para la variable A
  sc_in<sc_int<8>> rbIn; 	  //dirección de registro para la variable B
  sc_in<bool> clkIn; 		    //reloj (para controlar el moMemto de lectura y el moMemto de escritura)
  sc_in<sc_int<32>> wIn;  	//variable W
  sc_in<bool> weIn; 			    //"write enable" (booleano que representa si está habilitada la escritura)
  sc_out<sc_int<32>> aOut;  // variable A
  sc_out<sc_int<32>> bOut;  // variable B

  int memory[TAM_MEMORY];
  SC_CTOR(File);

private:
  void read();
  //void write();

};

#endif
