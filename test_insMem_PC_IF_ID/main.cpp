#include "Testbench.h"
#include "Ins_Mem.h"
#include "PC.h"
//#include "Mux.h"
#include "IF_ID.h"
#include "adder.h"

int sc_main(int argc, char *argv[])
{
	sc_time period(10, SC_NS);
	sc_time delay(10, SC_NS);
	sc_clock clock("clock", period, 0.5, delay, true);

	Testbench tb("tb");
	PC pc("pc");
	InstructionMemory im("im");
	Adder add("add");
//	Mux mux("mux");
	IF_ID if_id("if_id");

	tb.clk(clock);
	pc.clk(clock);
	im.clk(clock);
	add.clk(clock);
	if_id.clk(clock);

	sc_signal<sc_int<32>> adderMux, EX_MEMmux, muxPc, pcIF_ID, pcIm, imIF_ID, IF_ID_ID_EX, IF_ID_FileRegister1, pcAdder, tbAdder, tbPc /*tbAdder siempre escribe 1 sobre el puerto*/;
	sc_signal<bool> muxSg;

//	tb.muxSgOut(muxSg);
	tb.ID_EXIn(IF_ID_ID_EX);
	tb.register1In(IF_ID_FileRegister1);
	tb.adderIn2(tbAdder);
//	tb.tbPc(tbPc);
/*
	mux.aIn(adderMux);
	mux.bIn(EX_MEMmux);
	mux.sIn(muxSg);
	mux.cOut(muxPc);
*/
	pc.adressIn(adderMux);
	pc.adressAdderOut(pcAdder);
	pc.adressPC_IF_IDOut(pcIF_ID);
	pc.adressInstructionMemoryOut(pcIm);

	add.number_1In(pcAdder);
	add.number_2In(tbAdder);
	add.resultOut(adderMux);

	im.instructionNumberIn(pcIm);
	im.operationOut(imIF_ID);

	if_id.pcIn(pcIF_ID);
	if_id.insMemIn(imIF_ID);
	if_id.register1Out(IF_ID_FileRegister1);
	if_id.ID_EXOut(IF_ID_ID_EX);

	sc_start();

	return 0;
}