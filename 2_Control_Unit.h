#ifndef UNIDAD_CONTROL
#define UNIDAD_CONTROL

#include <systemc.h>
#include "And4Gate.h"
#include "OrGate.h"
#include "NotGate.h"
#include "divider.h"//MODULO PARA DIVIDIR LA SEÑAL DE <4> EN 4 CABLES INDIVIDUALES

class Unidad_Control : public sc_module
{
public:

	sc_in_clk clk;
	//SALIDAS DE LA UNIDAD DE CONTROL
	sc_out<sc_uint<2>> Ex_ALUOpOut;
	sc_out<bool> Ex_ALUSrcOut;
	sc_out<bool> Mem_MemWriteOut, Mem_MemReadOut, Mem_BranchOut;
	sc_out<bool> Wb_MemtoRegOut, Wb_RegWriteOut;

	//INTRUCCION A RECONOCER Y PROCESAR
	sc_in<sc_uint<4>> dir_In;

	SC_CTOR(Unidad_Control);
	~Unidad_Control();

private:
	void operation();
	//COMPUESRTAS AND ESPECIALES DE 4 ENTRADAS
	sc_vector<And4Gate> SC_NAMED(and_gate, 15);
	//CABLES PARA HACER CONEXIONES CON LAS COMPUESRTAS ANDS
	sc_vector<sc_signal<bool>> SC_NAMED(aInSg, 15);
	sc_vector<sc_signal<bool>> SC_NAMED(bInSg, 15);
	sc_vector<sc_signal<bool>> SC_NAMED(cInSg, 15);
	sc_vector<sc_signal<bool>> SC_NAMED(dInSg, 15);
	sc_vector<sc_signal<bool>> SC_NAMED(eOutSg, 15);
	sc_vector<sc_out<bool>> SC_NAMED(aux, 60);

	//COMPUESRTAS OR Y CABLES PARA CONECTARLAS
	sc_vector<OrGate> SC_NAMED(or_gate, 11);
	sc_vector<sc_signal<bool>> SC_NAMED(orCOut, 11);

	sc_vector<OrGate> SC_NAMED(or_gate2, 6);
	sc_vector<sc_signal<bool>> SC_NAMED(or2COut, 6);

	sc_vector<OrGate> SC_NAMED(or_gate3, 1);
	sc_signal<bool> or3COut;

	sc_vector<NotGate> SC_NAMED(not_gate2, 1);
	sc_signal<bool> not_gate2Out;

//Daniel
	//COMPUERTAS NOT Y CABLES PARA CONECTARLAS
	sc_vector<NotGate> SC_NAMED(Not_gate, 28);
	sc_vector<sc_signal<bool>> SC_NAMED(not_to_and, 28);
	sc_signal<bool> dir_In_0, dir_In_1,dir_In_2,dir_In_3;
	//PUNTERO PARA CREAR EL MODULO DIVIDER Y ASI HACER LA SEPARACION EN SEÑALES QUE ESTE MODULO OFRECE
	divider *Divider;
};

#endif
