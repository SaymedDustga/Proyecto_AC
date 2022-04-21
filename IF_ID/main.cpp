#include "Testbench.h"
#include "IF_ID.h"

int sc_main(int argc, char* argv[])
{
	sc_time period(10, SC_NS);
	sc_time delay(10, SC_NS);
	sc_clock clock("clock", period, 0.5, delay, true);

	Testbench tb("tb");
	IF_ID if_id("if_id");

	tb.clk(clock);
	if_id.clk(clock);

	sc_signal<sc_uint<32>> ins1Sg, ins2Sg, ins3Sg, ifid_idexSg, cp_ifidSg, insMem_ifidSg;
	sc_signal<sc_uint<5>> reg1Sg, reg2Sg;

	tb.cpOut(cp_ifidSg);
	if_id.cpIn(cp_ifidSg);

	tb.insMemOut(insMem_ifidSg);
	if_id.insMemIn(insMem_ifidSg);

	tb.register1In(reg1Sg);
	if_id.register1Out(reg1Sg);

	tb.register2In(reg2Sg);
	if_id.register2Out(reg2Sg);

	tb.instruction1In(ins1Sg);
	if_id.instruction1Out(ins1Sg);

	tb.instruction2In(ins2Sg);
	if_id.instruction2Out(ins2Sg);

	tb.instruction3In(ins3Sg);
	if_id.instruction3Out(ins3Sg);

	tb.ID_EXIn(ifid_idexSg);
	if_id.ID_EXOut(ifid_idexSg);

	sc_start();

	return 0;
}