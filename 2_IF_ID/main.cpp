#include "2_IF_ID.h"
#include "Testbench.h"

int sc_main(int argc, char *argv[])
{
	sc_time period(10, SC_NS);
	sc_time delay(0, SC_NS);
	sc_clock clock("clock", period, 5, delay, false);

	IF_ID if_id("if_id");
	Testbench tb("tb");

	sc_signal<sc_uint<32>> insMemSg;
	sc_signal<sc_int<32>> pcSg, ID_EX0Sg;
	sc_signal<sc_uint<5>> fileRegister1Sg, fileRegister2Sg, ID_EX2Sg;
	sc_signal<sc_int<18>> immGenSg;
	sc_signal<sc_uint<4>> ID_EX1Sg, ID_UnidadControlSg;

	if_id.pcIn(pcSg);
	if_id.insMemIn(insMemSg);
	if_id.fileRegister1Out(fileRegister1Sg);
	if_id.fileRegister2Out(fileRegister2Sg);
	if_id.immGenOut(immGenSg);
	if_id.ID_EX0Out(ID_EX0Sg);
	if_id.ID_EX1Out(ID_EX1Sg);
	if_id.ID_unidadControlOut(ID_UnidadControlSg);
	if_id.ID_EX2Out(ID_EX2Sg);

	tb.pcOut(pcSg);
	tb.insMemOut(insMemSg);
	tb.fileRegister1In(fileRegister1Sg);
	tb.fileRegister2In(fileRegister2Sg);
	tb.immGenIn(immGenSg);
	tb.ID_EX0In(ID_EX0Sg);
	tb.ID_EX1In(ID_EX1Sg);
	tb.ID_unidadControlIn(ID_UnidadControlSg);
	tb.ID_EX2In(ID_EX2Sg);

	tb.clk(clock);
	if_id.clk(clock);

	sc_start();

	return 0;
}