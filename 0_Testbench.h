#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>
#include <systemc.h>


class Testbench : public sc_module {
public:
	/*
		Todas los puertos de entrada se han llamado de la misma manera que sus pares 
		en los modulos a chequear
	*/
	//señal de control 
	sc_in_clk clk;

	//ins_men
	sc_in<sc_int<32>> instructionNumberIn;		//cable que viene desde pc
	sc_in<sc_uint<32>> operationOut;			//salida hacia el primer registro de encausamiento IF_ID

	//Unidad control
	sc_in<sc_uint<2>> Ex_ALUOpOut;
 	sc_in<bool> Ex_ALUSrcOut;
 	sc_in<bool> Mem_MemWriteOut, Mem_MemReadOut, Mem_BranchOut;
 	sc_in<bool> Wb_MemtoRegOut, Wb_RegWriteOut;
  	sc_in<sc_uint<4>> dir_In;

	//register
  	sc_in<sc_uint<5>> rwIn; 	  //direccion a escribir
  	sc_in<sc_uint<5>> raIn; 	  //primera direccion a leer
  	sc_in<sc_uint<5>> rbIn; 	  //segunda direccion a leer
 	sc_in<sc_int<32>> wIn;  	  //valor a escribir en la direccion 'rwIn'
  	sc_in<bool> weIn; 			  //bandera que indica si se puede escribir 
 	sc_in<sc_int<32>> aOut;  	  //salida del primer valor leido
  	sc_in<sc_int<32>> bOut;  	  //salida del segundo valor leido


	//alu
 	sc_in<sc_uint<4>> insIn_alu;						//valor instantaneo
	sc_in<sc_int<32>> number_1In_alu, number_2In_alu;	//primer operando
  	sc_in<sc_int<32>>  resultOut_alu;					//segundo operando
  	sc_in<bool> zeroOut_alu;							//bit que va hacia el branch para indicar salto


	//data_memory
  	sc_in<sc_int<32>> addressIn;         //dirección de registro 
 	sc_in<sc_int<32>> read_dataOut;     //valor a escribir
 	sc_in<sc_int<32>> write_dataIn;    // valor a escribir
 	sc_in<bool> writeIn, readIn;      // banderas que habilitan lectura y escritura	
	SC_CTOR(Testbench);

	//mux
 	sc_in<sc_int<32>> aIn, bIn; //entradas
  	sc_in<sc_int<32>> cOut;		//salida
  	sc_in<bool> sIn;			//toma de decision entre las dos salidas

private:
	void operation();
	void print();
};

#endif
