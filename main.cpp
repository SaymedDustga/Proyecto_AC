#include "Testbench.h"
#include "ArchivoRegistro.h"

int sc_main(int argc, char* argv[]){

	sc_time period(10, SC_NS);
	sc_time delay(10, SC_NS);
	sc_clock clock("clock", period, 0.5, delay, true);

	Testbench tb("tb");
	ArchivoRegistro ArchReg("ArchReg");

	tb.clk(clock);
	ArchReg.clk(clock);

	sc_signal<sc_uint> 
	mux-pc_Sg, pc-insMem_Sg, pc-add_Sg, pc-IF/ID_Sg, insMem-IF/ID_Sg, IF/ID-RegWrite-Reg1_Sg, IF/ID-RegWrite-Reg2_Sg,
	IF/ID-ID/EX-Instruction1_Sg, IF/ID-ImmGen-Instruction2_Sg, IF/ID-ID/EX-Instruction3_Sg, IF/ID-ID/EX_Sg
	RegWrite-ID/EX-Read1_Sg, RegWrite-ID/EX-Read2_Sg, ImmGen-ID/EX_Sg;
	sc_signal<sc_int> 
//	sc_signal<bool> weSg;

	tb.wOut(wSg);
	ArchReg.wIn(wSg);

	tb.weOut(weSg);
	ArchReg.weIn(weSg);

	tb.aIn(aSg);
	ArchReg.aOut(aSg);

	tb.bIn(bSg);
	ArchReg.bOut(bSg);

	tb.rwOut(rwSg);
	ArchReg.rwIn(rwSg);

	tb.raOut(raSg);
	ArchReg.raIn(raSg);

	tb.rbOut(rbSg);
	ArchReg.rbIn(rbSg);
	sc_start();

	return 0;
}