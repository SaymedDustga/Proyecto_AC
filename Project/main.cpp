#include "0_3_5_Mux.h"

#include "1_Ins_Mem.h"
#include "1_PC.h"


#include "2_Imm_Gen.h"
#include "2_IF_ID.h"
#include "2_File.h"
#include "2_Unidad_Control.h"

#include "3_ALU.h"
#include "3_alu_control.h"
#include "1_3_adder.h"
#include "3_ID_EX.h"

#include "4_EX_MEM.h"
#include "4_Data_Memory.h"
#include "4_branch.h"

#include "5_MEM_WB.h"

#include "1.h"

int sc_main(int argc, char *argv[])
{
	sc_time period(10, SC_NS);
	sc_time delay(10, SC_NS);
	sc_clock clock("clock", period, 0.5, delay, true);



	//===========================================================================================
	// CABLES DE UNIDAD DE CONTROL FASE ¿Inicial?

	sc_signal<sc_int<32>> instructionM_ifId, pc_instructionM, pc_ifId, pc_sum;
	/*
	Hola bro... como no encontre el add de esta fase  xd no se donde esta :'v'
	*/	
	sc_signal<sc_int<32>> exMem_muxPC, muxPc_pc, adder_Mux, onlySum4;
	sc_signal<bool> branch_muxPC;

	Mux mux("mux");
	IF_ID IF_ID("IF_ID");
	InstructionMemory InstructionMemory("InstructionMemory");
	PC PC("PC");
	Adder adder01("adder01");

	Uno one("one");
	one.uno(onlySum4);

	mux.sIn(branch_muxPC);
	mux.aIn(adder_Mux);
	mux.bIn(exMem_muxPC);
	mux.cOut(muxPc_pc);

	PC.adressIn(muxPc_pc);
	PC.adressAdderOut(pc_sum);//cable que va hacia al sumador in
	PC.adressPC_IF_IDOut(pc_ifId);
	PC.adressInstructionMemoryOut(pc_instructionM);

	InstructionMemory.instructionNumberIn(pc_instructionM);
	InstructionMemory.operationOut(instructionM_ifId);

	adder01.number_1In(pc_sum);
	adder01.number_2In(onlySum4);
	adder01.resultOut(adder_Mux);

	//===========================================================================================
	// CABLES DE UNIDAD DE CONTROL FASE IF-ID
	sc_signal<bool>    Ex_ALUSrc0;
	sc_signal<sc_uint<2>>	Ex_ALUOp0;
	sc_signal<bool> Mem_MemWrite0, Mem_MemRead0, Mem_Branch0;
	sc_signal<bool> Wb_MemtoReg0, Wb_RegWrite0;
	sc_signal<bool> reg_write;	
	sc_signal<sc_int<8>> ifId_ImmGen;
	sc_signal<sc_int<32>> if_ex0, ImmGen_idEx;
	sc_signal<sc_int<32>> reg_ex0, reg_ex1, muxWB_register/*viene desde WB*/;

	sc_signal<sc_int<8>> if_ex1, if_ex2,  IF_ID_FileRegister1, IF_ID_FileRegister2;
	sc_signal<sc_int<8>> ifID_unidadControl;
	sc_signal<sc_int<8>>  MemWb_register;//viene desde WB

	File File("File");
	Unidad_Control Unidad_Control("Unidad_Control");
	Imm_Gen Imm_Gen("Imm_Gen");
	id_ex id_ex("id_ex");

	IF_ID.pcIn(pc_ifId);
	IF_ID.insMemIn(instructionM_ifId);
	IF_ID.ID_EX0Out(if_ex0);
	IF_ID.fileRegister1Out(IF_ID_FileRegister1);
	IF_ID.fileRegister2Out(IF_ID_FileRegister2);
	IF_ID.immGenOut(ifId_ImmGen);
	IF_ID.ID_EX1Out(if_ex1);
	IF_ID.ID_EX2Out(if_ex2);
	IF_ID.ID_unidadControl(ifID_unidadControl);

	Unidad_Control.dir_In(ifID_unidadControl);

	Unidad_Control.Ex_ALUOpOut(Ex_ALUOp0);
	Unidad_Control.Ex_ALUSrcOut(Ex_ALUSrc0);
	Unidad_Control.Mem_MemWriteOut(Mem_MemWrite0);
	Unidad_Control.Mem_MemReadOut(Mem_MemRead0);
	Unidad_Control.Mem_BranchOut(Mem_Branch0);
	Unidad_Control.Wb_MemtoRegOut(Wb_MemtoReg0);
	Unidad_Control.Wb_RegWriteOut(Wb_RegWrite0);

	File.rwIn(MemWb_register);	
	File.wIn(muxWB_register);			 
	File.weIn(reg_write);

	File.raIn(IF_ID_FileRegister1);  
	File.rbIn(IF_ID_FileRegister2); 
	File.aOut(reg_ex0);  
	File.bOut(reg_ex1);  

	Imm_Gen.IF_IDIn(ifId_ImmGen);
	Imm_Gen.ID_EXOut(ImmGen_idEx);

	id_ex.Ex_ALUSrcIn(Ex_ALUSrc0), id_ex.Ex_ALUOpIn(Ex_ALUOp0);
	id_ex.Mem_MemWriteIn(Mem_MemWrite0), id_ex.Mem_MemReadIn(Mem_MemRead0), id_ex.Mem_BranchIn(Mem_Branch0);
	id_ex.Wb_MemtoRegIn(Wb_MemtoReg0), id_ex.Wb_RegWriteIn(Wb_RegWrite0);

	id_ex.memo_In[0](reg_ex0);
	id_ex.memo_In[1](reg_ex1);

	id_ex.id_ex0In(if_ex0);
	id_ex.Imm_genIn(ImmGen_idEx);// aqui sigue el problema de gem XD
	id_ex.id_ex1In(if_ex1);
	id_ex.id_ex2In(if_ex2);

	//========================================================================================================
	// CABLES DE UNIDAD DE CONTROL FASE ID-EX
	sc_signal<bool>  Ex_ALUSrc1;
	sc_signal<sc_uint<2>> Ex_ALUOp1;
	sc_signal<bool> Mem_MemWrite1, Mem_MemRead1, Mem_Branch1;
	sc_signal<bool> Wb_MemtoReg1, Wb_RegWrite1;

	sc_signal<sc_int<32>> idEx_alu, idEx_muxEx_exMem, idEx_sumAdd1, idEx_sumAdd, idEx_mux ,addSum_exMem;  
	sc_signal<sc_int<32>>  muxEx_alu, alu_exMem_32bit;   
	sc_signal<sc_int<8>>  idEx_aluControl, idEx_exMem, aluControl_alu;
	sc_signal<bool> alu_exMem_1bit;

	Adder addSum("addSum");
	Mux ex_mux("ex_mux");//EL ERROR DE ESTA LINEA CREO QUE TIENE QUE VER CON QUE HAY UN MUX QUE SE LLAMA 'MUX'
	ALU alu("alu");
	ALU_CONTROL alu_control("alu_control");
	EX_MEM ex_mem("ex_mem");

	id_ex.Ex_ALUSrcOut(Ex_ALUSrc1), id_ex.Ex_ALUOpOut(Ex_ALUOp1);
	id_ex.Mem_MemWriteOut(Mem_MemWrite1), id_ex.Mem_MemReadOut(Mem_MemRead1), id_ex.Mem_BranchOut(Mem_Branch1);
	id_ex.Wb_MemtoRegOut(Wb_MemtoReg1), id_ex.Wb_RegWriteOut(Wb_RegWrite1);


	id_ex.memo_Out[0](idEx_alu);
	id_ex.memo_Out[1](idEx_muxEx_exMem);

	id_ex.id_ex0Out(idEx_sumAdd1);
	id_ex.Imm_gen1Out(idEx_sumAdd);
	id_ex.Imm_gen2Out(idEx_mux);
	id_ex.id_ex1Out(idEx_aluControl);
	id_ex.id_ex2Out(idEx_exMem);

	addSum.number_1In(idEx_sumAdd1);
	addSum.number_2In(idEx_sumAdd);
	addSum.resultOut(addSum_exMem);

	ex_mux.sIn(Ex_ALUSrc1);
	ex_mux.aIn(idEx_muxEx_exMem);
	ex_mux.bIn(idEx_mux);
	ex_mux.cOut(muxEx_alu);

	alu.number_1In(idEx_alu);
	alu.number_2In(muxEx_alu);
	alu.insIn(aluControl_alu);
	alu.resultOut(alu_exMem_32bit);
	alu.zeroOut(alu_exMem_1bit);

	alu_control.Ex_ALUOpIn(Ex_ALUOp1);
	alu_control.dir_In(idEx_aluControl);
	alu_control.instruction_aluOut(aluControl_alu);

	ex_mem.alu_to_brachIn(alu_exMem_1bit);
	ex_mem.Mem_MemWriteIn(Mem_MemWrite1);
	ex_mem.Mem_MemReadIn(Mem_MemRead1);
	ex_mem.Mem_BranchIn(Mem_Branch1);
	ex_mem.Wb_MemtoRegIn(Wb_MemtoReg1);
	ex_mem.Wb_RegWriteIn(Wb_RegWrite1);

	ex_mem.memo_In[0](addSum_exMem);
	ex_mem.memo_In[1](alu_exMem_32bit);
	ex_mem.memo_In[2](idEx_muxEx_exMem);
	ex_mem.dir_In(idEx_exMem);

	//========================================================================================
	// CABLES DE UNIDAD DE CONTROL FASE EX-Mem
	sc_signal<bool> Mem_MemWrite2, Mem_MemRead2, Mem_Branch2, exMem_branch;
	sc_signal<bool> Wb_MemtoReg2, Wb_RegWrite2;
	sc_signal<sc_int<32>> exMem_dataMemoryAddress_MemWb, exMem_dataMemoryData, dataMemory_MemWb;  
	sc_signal<sc_int<8>>  exMem_MemWb;

	ex_mem.Mem_MemWriteOut(Mem_MemWrite2), ex_mem.Mem_MemReadOut(Mem_MemRead2), ex_mem.Mem_BranchOut(Mem_Branch2);
	ex_mem.Wb_MemtoRegOut(Wb_MemtoReg2), ex_mem.Wb_RegWriteOut(Wb_RegWrite2);
	ex_mem.alu_to_brachOut(exMem_branch);

	ex_mem.memo_Out[0](exMem_muxPC);
	ex_mem.memo_Out[1](exMem_dataMemoryAddress_MemWb);
	ex_mem.memo_Out[2](exMem_dataMemoryData);
	ex_mem.dir_Out(exMem_MemWb);

	Branch branch("branch");
	Data_Memory data_memory("data_memory");
	MEM_WB mem_wb("mem_wb");

	branch.jumpIn(exMem_branch);
	branch.addressIn(Mem_Branch2);
	branch.answerOut(branch_muxPC);


	data_memory.addressIn(exMem_dataMemoryAddress_MemWb);
	data_memory.write_dataIn(exMem_dataMemoryData);
	data_memory.readIn(Mem_MemRead2);
	data_memory.writeIn(Mem_MemWrite2);
	data_memory.read_dataOut(dataMemory_MemWb);

	mem_wb.Wb_MemtoRegIn(Wb_MemtoReg2);
	mem_wb.Wb_RegWriteIn(Wb_RegWrite2);
	mem_wb.Wb_RegWriteOut(reg_write);
	mem_wb.dir_In(exMem_MemWb);

	mem_wb.memo_In[0](dataMemory_MemWb);
	mem_wb.memo_In[1](exMem_dataMemoryAddress_MemWb);

	//========================================================================================
	// CABLES DE UNIDAD DE CONTROL FASE Mem-WB

	sc_signal<bool> Wb_MemtoReg3;
	sc_signal<sc_int<32>> MemWb_muxWb1, MemWb_muxWb2;  


	mem_wb.Wb_MemtoRegOut(Wb_MemtoReg3);

	mem_wb.memo_Out[0](MemWb_muxWb1);
	mem_wb.memo_Out[1](MemWb_muxWb2);
	mem_wb.dir_Out(MemWb_register);

	Mux muxWB("muxWB");

	muxWB.sIn(Wb_MemtoReg3);
	muxWB.aIn(MemWb_muxWb1);
	muxWB.bIn(MemWb_muxWb2);
	muxWB.cOut(muxWB_register);

	//clocks
	PC.clk(clock);
	File.clkIn(clock);
	data_memory.clkIn(clock);

	IF_ID.clk(clock);
	id_ex.clkIn(clock);
	ex_mem.clkIn(clock);
	mem_wb.clkIn(clock);

	InstructionMemory.clk(clock);

	sc_start();

	return 0;
}