#include "Testbench.h"
#include "Ins_Mem.h"
#include "PC.h"
#include "Mux.h"
#include "IF_ID.h"
#include "adder.h"
#include "File.h"
#include "IF_ID.h"
#include "ID_EX.h"
#include "Ins_Mem.h"
#include "Mux.h"

int sc_main(int argc, char *argv[])
{
	sc_time period(10, SC_NS);
	sc_time delay(10, SC_NS);
	sc_clock clock("clock", period, 0.5, delay, true);

	Testbench tb("tb");
	PC pc("pc");
	InstructionMemory im("im");
	Adder add("add");
	Mux mux("mux");
	IF_ID if_id("if_id");
	File File("file");
	Imm_Gen imm_gen("Imm_Gen")
		id_ex id_ex("id_ex");

	tb.clk(clock);
	pc.clk(clock);
	im.clk(clock);
	add.clk(clock);
	if_id.clk(clock);
	file.clkIn(clock);
	id_ex.clkIn(clock);
	sc_signal<sc_int<32>> adderMux, EX_MEMmux, muxPc, pcIF_ID, pcIm, imIF_ID, IF_ID_ID_EX, IF_ID_FileRegister1, IF_ID_FileRegister2, pcAdder, tbAdder /*tbAdder siempre escribe 1 sobre el puerto*/;

	// process if--------------------------------------
	sc_signal<sc_int<8>> if_control;
	sc_signal<sc_int<32>> if_ex0, if_ImmGen, ImmGen_ex;
	sc_signal<sc_int<8>> if_ex1, if_ex2;

	// cables desde file
	sc_signal<sc_int<32>> reg_ex0, reg_ex1;

	// CABLES DESDE WB
	sc_signal<sc_int<32>> wb_REG_write, wb_REG_data;

	// CABLES DE UNIDAD DE CONTROL FACE IF-ID
	sc_signal<sc_int<2>> Ex_ALUSrc0, Ex_ALUOp0;
	sc_signal<bool> Men_MemWrite0, Men_MemRead0, Men_Branch0;
	sc_signal<bool> Wb_MemtoReg0, Wb_no_idea0;
	sc_signal<bool> reg_write;	
	//proces id--------------------------------------------
	sc_signal<sc_int<32>> ex_alu1, ex_alu2;   


	// CABLES DE UNIDAD DE CONTROL FACE ID-EX
	sc_signal<sc_int<2>> Ex_ALUSrc1, Ex_ALUOp1;
	sc_signal<bool> Men_MemWrite1, Men_MemRead1, Men_Branch1;
	sc_signal<bool> Wb_MemtoReg1, Wb_no_idea1;
	//--------------------------------------------------
	//===========================================================================================
	if_id.ID_EX0Out(if_ex0);
	if_id.fileRegister1Out(IF_ID_FileRegister1);
	if_id.fileRegister2Out(IF_ID_FileRegister2);
	if_id.immGenOut(if_ImmGen);
	if_id.ID_EX1Out(if_ex1);
	if_id.ID_EX2Out(if_ex2);

	file.rwIn(wb_REG_write);		// dirección de registro para la variable W
	file.raIn(IF_ID_FileRegister1); // dirección de registro para la variable A
	file.rbIn(IF_ID_FileRegister2); // dirección de registro para la variable B
	file.wIn(wb_REG_data);			// variable W
	file.weIn(reg_write);

	file.aOut(reg_ex0); // variable A
	file.bOut(reg_ex1); // variable B

	id_ex.Ex_ALUSrcIn(Ex_ALUSrc0), id_ex.Ex_ALUOpIn(Ex_ALUOp0);
	id_ex.Men_MemWriteIn(Men_MemWrite0), id_ex.Men_MemReadIn(Men_MemRead0), id_ex.Men_BranchIn(Men_Branch0);
	id_ex.Wb_MemtoRegIn(Wb_MemtoReg0), id_ex.Wb_no_ideaIn(Wb_no_idea0);

	id_ex.memo_In[0](reg_ex0);
	id_ex.memo_In[1](reg_ex1);

	id_ex.id_ex0In.(if_ex0);
	id_ex.Imm_genIn(ImmGen_ex);
	id_ex.id_ex1In(if_ex1);
	id_ex.id_ex2In(if_ex2);

	//========================================================================================================

	id_ex.Ex_ALUSrcOut(Ex_ALUSrc1), id_ex.Ex_ALUOpOut(Ex_ALUSrc1);
	id_ex.Men_MemWriteOut(Ex_ALUSrc1), id_ex.Men_MemReadOut(Ex_ALUSrc1), id_ex.Men_BranchOut(Ex_ALUSrc1);
	id_ex.Wb_MemtoRegOut, id_ex.Wb_no_ideaOut(Ex_ALUSrc1);



	id_ex.memo_Out[0](ex_alu1);
	id_ex.memo_Out[1](ex_alu2);
	id_ex.id_ex0Out();s
	id_ex.Imm_genOut();
	id_ex.id_ex1Out();
	id_ex.id_ex2Out();


	//========================================================================================


	imm_gen.IF_IDIn(if_ImmGen);
	imm_gen.ID_EXOut(ImmGen_ex);

	sc_signal<bool> muxSg;

	tb.muxSgOut(muxSg);
	tb.ID_EXIn(IF_ID_ID_EX);
	tb.register1In(IF_ID_FileRegister1);
	tb.adderIn2(tbAdder);
	tb.muxIn2(EX_MEMmux);

	mux.aIn(adderMux);
	mux.bIn(EX_MEMmux);
	mux.sIn(muxSg);
	mux.cOut(muxPc);

	pc.adressIn(muxPc);
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