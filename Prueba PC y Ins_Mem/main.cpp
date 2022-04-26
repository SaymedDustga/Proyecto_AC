#include "Testbench.h"
#include "Ins_Mem.h"

int sc_main(int argc, char *argv[])
{
	sc_time period(10, SC_NS);
	sc_time delay(10, SC_NS);
	sc_clock clock("clock", period, 0.5, delay, true);

	Testbench tb("tb");
	PC pc("pc");
	InstructionMemory im("im");

	tb.clk(clock);
	pc.clk(clock);
	im.clk(clock);

	sc_signal<sc_uint<32>> tbPc, pcIm, imTb;

	tb.adressOut(tbPc);
	tb.operationIn(imTb);

	pc.adressIn(tbPc);
	pc.adressOut(pcIm);

	im.instructionNumberIn(pcIm);
	im.operationOut(imTb);

	sc_start();

	return 0;
}