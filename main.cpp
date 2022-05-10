#include "0_3_5_Mux.h"
/*
	LA ESPECIAL NUMERACION DE ESTE ARHCIVO .h INDICA QUE SERAN CREADO
	3 MODULOS DEL TIPO MULTIPLEXORES
		UNO PARA IF(FASE 0)
		UNO PARA EX(FASE 3)
		UNO PARA WB(FASE 5)
*/
#include "0_Testbench.h"

#include "1.h"
#include "1_3_Adder.h"
/*
	LA ESPECIAL NUMERACION DE ESTE ARHCIVO .h INDICA QUE SERAN CREADO
	3 MODULOS DEL TIPO ADDER O SUMADOR
		UNO PARA ID(FASE 1)
		UNO PARA EX(FASE 3)
*/
#include "1_Instruction_Memory.h"
#include "1_PC.h"

#include "2_Control_Unit.h"
#include "2_Register_File.h"
#include "2_IF_ID.h"
#include "2_Imm_Gen.h"

#include "3_ALU.h"
#include "3_ALU_Control_Unit.h"
#include "3_ID_EX.h"

#include "4_Branch.h"
#include "4_Data_Memory.h"
#include "4_EX_MEM.h"

#include "5_MEM_WB.h"

/*
	El numero al principio de cada archivo .h significa en que parte del pipelining
	participara este modulo
*/
int sc_main(int argc, char *argv[])
{
	//DECLARACION DEL RELOJ
	sc_time period(10, SC_NS);
	sc_time delay(0, SC_NS);
	sc_clock clock("clock", period, 0.5, delay, true);

	//DECLARACION DEL TEST DEL PROGRAMA CUYAS ENTRADAS NECESARIAS SE IRAN CONECTANDO 
	//A LO LARGO DE ESTE ARCHIVO PRINCIPAL
	Testbench Testbench("Testbench");

	/*
		LOS PUEROS DEL TESTBENCH HAN SIDO NOMBRADO CON LOS MISMOS NOMBRE DE LOS PUERTOS
		QUE EMITEN LAS SEÑALES QUE LOS TEST RECIBEN, ESTO CON EL FIN DE NO DIFICULTAR LA
		LECTURA DEL CODIGO
	*/


	//===========================================================================================
	// CABLES DE UNIDAD DE CONTROL FASE INICIAL

	sc_signal<sc_int<32>> pc_instructionM, pc_ifId, pc_sum;
	sc_signal<sc_uint<32>> instructionM_ifId;

	/*
		LA MAYORIA DE LOS CABLES ESTAN NOMBRADOS DE UNA MANERA PARTICULAR
		(CON EXEPCION DE ALGUNOS CASOS ESPECIALES EN LOS QUE CONTAREMOS LOS CABLES DE
		LAS SEÑALES DE CONTROL).EN EL LADO IZQUIERDO TIENE EL MODULO ORIGEN Y EN LA PARTE DERECHA 
		EL MODULO DESTINO

		SC_INT<XVALOR> MODULOINICIO_MODULODESTINO;

		ESTO PARA PODER SEGUIR CON MAYOR FACILIDAD LAS CONEXIONES ENTRE LOS MODULOS
	*/

	sc_signal<sc_int<32>> exMem_muxPC, muxPc_pc, adder_Mux, onlySum4;
	sc_signal<bool> branch_muxPC;

	//MODULOS DE LA FASE INICIAL
	Mux mux("mux");
	InstructionMemory InstructionMemory("InstructionMemory");
	PC PC("PC");
	Adder adder01("adder01");
	Uno one("one");

	//PRIMER REGISTRO DE ENCAUSAMIENTO
	IF_ID IF_ID("IF_ID");

	one.uno(onlySum4);

	mux.sIn(branch_muxPC);
	mux.aIn(adder_Mux);
	mux.bIn(exMem_muxPC);
	mux.cOut(muxPc_pc);


	PC.adressIn(muxPc_pc);
	PC.adressAdderOut(pc_sum);
	PC.adressPC_IF_IDOut(pc_ifId);
	PC.adressInstructionMemoryOut(pc_instructionM);

	
	InstructionMemory.instructionNumberIn(pc_instructionM);
	InstructionMemory.operationOut(instructionM_ifId);

	//CONENCTAMOS LAS SALIDAS DE "InstructionMemory" AL TESTBENCH
	Testbench.instructionNumberIn(pc_instructionM);
	Testbench.operationOut(instructionM_ifId);

	adder01.number_1In(pc_sum);
	adder01.number_2In(onlySum4);
	adder01.resultOut(adder_Mux);

	IF_ID.pcIn(pc_ifId);
	IF_ID.insMemIn(instructionM_ifId);

	
	//===========================================================================================
	// CABLES DE UNIDAD DE CONTROL FASE IF-ID
	sc_signal<bool>    Ex_ALUSrc0;
	sc_signal<sc_uint<2>>	Ex_ALUOp0;
	sc_signal<bool> Mem_MemWrite0, Mem_MemRead0, Mem_Branch0;
	sc_signal<bool> Wb_MemtoReg0, Wb_RegWrite0;
	sc_signal<bool> reg_write;	
	sc_signal<sc_int<18>> ifId_ImmGen;
	sc_signal<sc_int<32>> if_ex0, ImmGen_idEx;
	sc_signal<sc_int<32>> reg_ex0, reg_ex1, muxWB_register/*viene desde WB*/;


	sc_signal<sc_uint<4>> if_ex1;
	sc_signal<sc_uint<5>> if_ex2, IF_ID_FileRegister1, IF_ID_FileRegister2;
	sc_signal<sc_uint<4>> ifID_unidadControl;
	sc_signal<sc_uint<5>>  MemWb_register;

	// DECLARAMOS LOS MODULOS DE LA FASE IF-ID
	RegisterFile File("File");
	Unidad_Control Unidad_Control("Unidad_Control");
	Imm_Gen Imm_Gen("Imm_Gen");

	//SEGUNDO REGISTRO DE ENCAUSAMIENTO
	id_ex id_ex("id_ex");


	IF_ID.ID_EX0Out(if_ex0);
	IF_ID.fileRegister1Out(IF_ID_FileRegister1);
	IF_ID.fileRegister2Out(IF_ID_FileRegister2);
	IF_ID.immGenOut(ifId_ImmGen);
	IF_ID.ID_EX1Out(if_ex1);
	IF_ID.ID_EX2Out(if_ex2);
	IF_ID.ID_unidadControlOut(ifID_unidadControl);

	Unidad_Control.dir_In(ifID_unidadControl);
	//CONECTAMOS LA UNICA SALIDA DE LA UNIDAD DE 
	Testbench.dir_In(ifID_unidadControl);

	//DESDE AQUI SALEN TODAS LAS SEÑALES DE CONTROL
	//NOTA  :  ESTA UNIDAD ESTA CREADA EN BAJO NIVEL
	Unidad_Control.Ex_ALUOpOut(Ex_ALUOp0);
	Unidad_Control.Ex_ALUSrcOut(Ex_ALUSrc0);
	Unidad_Control.Mem_MemWriteOut(Mem_MemWrite0);
	Unidad_Control.Mem_MemReadOut(Mem_MemRead0);
	Unidad_Control.Mem_BranchOut(Mem_Branch0);
	Unidad_Control.Wb_MemtoRegOut(Wb_MemtoReg0);
	Unidad_Control.Wb_RegWriteOut(Wb_RegWrite0);

	//CONENCTAMOS LAS SALIDAS DE "Unidad_Control" AL TESTBENCH
	Testbench.Ex_ALUOpOut(Ex_ALUOp0);
	Testbench.Ex_ALUSrcOut(Ex_ALUSrc0);
	Testbench.Mem_MemWriteOut(Mem_MemWrite0);
	Testbench.Mem_MemReadOut(Mem_MemRead0);
	Testbench.Mem_BranchOut(Mem_Branch0);
	Testbench.Wb_MemtoRegOut(Wb_MemtoReg0);
	Testbench.Wb_RegWriteOut(Wb_RegWrite0);


	//ARCHIVO DE REGISTRO 
	//NOTA : CONSTRUIDO EN BAJO NIVEL
	File.rwIn(MemWb_register);	
	File.wIn(muxWB_register);
	File.raIn(IF_ID_FileRegister1);  
	File.rbIn(IF_ID_FileRegister2); 
	File.aOut(reg_ex0);  
	File.bOut(reg_ex1);  	
	//BANDERA QUE EMITIDA DESDE LA UNIDAD DE CONTROL PERO QUE ATRAVIEZA CASI TODO EL CICLO
	//DE DATOS HASTA LLEGAR AL FIN A EL REGISTRO			 
	File.weIn(reg_write);



	//CONENCTAMOS LAS SALIDAS DE "File"(ARCHIVO DE REGISTRO) AL TESTBENCH
	Testbench.rwIn(MemWb_register);	
	Testbench.wIn(muxWB_register);			 
	Testbench.weIn(reg_write);
	Testbench.raIn(IF_ID_FileRegister1);  
	Testbench.rbIn(IF_ID_FileRegister2); 
	Testbench.aOut(reg_ex0);  
	Testbench.bOut(reg_ex1);

	Imm_Gen.IF_IDIn(ifId_ImmGen);
	Imm_Gen.ID_EXOut(ImmGen_idEx);

	//CONECTAMOS LAS SEÑALES QUE VIENEN DESDE LA UNIDAD DE CONTROL A LAS ENTRADAS DEL REGISTRO id_ex 
	id_ex.Ex_ALUSrcIn(Ex_ALUSrc0), id_ex.Ex_ALUOpIn(Ex_ALUOp0);
	id_ex.Mem_MemWriteIn(Mem_MemWrite0), id_ex.Mem_MemReadIn(Mem_MemRead0), id_ex.Mem_BranchIn(Mem_Branch0);
	id_ex.Wb_MemtoRegIn(Wb_MemtoReg0), id_ex.Wb_RegWriteIn(Wb_RegWrite0);

	id_ex.memo_In[0](reg_ex0);
	id_ex.memo_In[1](reg_ex1);

	id_ex.id_ex0In(if_ex0);
	id_ex.Imm_genIn(ImmGen_idEx);
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

	sc_signal<sc_uint<4>> aluControl_alu, idEx_aluControl;
	sc_signal<sc_uint<5>>  idEx_exMem;
	sc_signal<bool> alu_exMem_1bit;

	// DECLARAMOS LOS MODULOS DE LA FASE ID-EX
	Adder addSum("addSum");
	ALU alu("alu");
	ALU_CONTROL alu_control("alu_control");
	//ESTE ES EL MULTIPLEXOR DE LA FASE DE EXECUTION (EX)
	Mux ex_mux("ex_mux");
	
	//TERCER REGISTRO DE ENCAUSAMIENTO	
	EX_MEM ex_mem("ex_mem");

	//CONECTAMOS LAS SEÑALES DE CONTROL A LOS CABLES DE SALIDA DE ID_EX
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

	//CONENCTAMOS LAS SALIDAS DE "alu" AL TESTBENCH
	Testbench.number_1In_alu(idEx_alu);
	Testbench.number_2In_alu(muxEx_alu);
	Testbench.insIn_alu(aluControl_alu);
	Testbench.resultOut_alu(alu_exMem_32bit);
	Testbench.zeroOut_alu(alu_exMem_1bit);


	alu_control.Ex_ALUOpIn(Ex_ALUOp1);
	alu_control.dir_In(idEx_aluControl);
	alu_control.instruction_aluOut(aluControl_alu);

	//CONECTAMOS LAS SEÑALES DE CONTROL VIENEN DESDE ID_EX  A LAS ENTRADAS DEL REGISTRO ex_mem
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
	sc_signal<sc_int<32>> exMem_dataMemoryAddress, exMem_MemWb32bits, exMem_dataMemoryData, dataMemory_MemWb;  
	sc_signal<sc_uint<5>>  exMem_MemWb;

	// DECLARAMOS LOS MODULOS DE LA FASE EX-Mem
	Branch branch("branch");
	Data_Memory data_memory("data_memory");

	//CUARTO REGISTRO DE ENCAUSAMIENTO
	MEM_WB mem_wb("mem_wb");

	//CONECTAMOS LOS CABLES NECESARIOS A LAS SALIDAS DEL REGISTRO ex_mem PARA TRANSMITIR LAS SEÑALES DE CONTROL
	ex_mem.Mem_MemWriteOut(Mem_MemWrite2), ex_mem.Mem_MemReadOut(Mem_MemRead2), ex_mem.Mem_BranchOut(Mem_Branch2);
	ex_mem.Wb_MemtoRegOut(Wb_MemtoReg2), ex_mem.Wb_RegWriteOut(Wb_RegWrite2);
	ex_mem.alu_to_brachOut(exMem_branch);
	ex_mem.dir_Out(exMem_MemWb);

	ex_mem.memo_Out[0](exMem_muxPC);
	ex_mem.memo_Out[1](exMem_dataMemoryAddress);	
	ex_mem.memo_Out[2](exMem_dataMemoryData);
	ex_mem.memo_Out[3](exMem_MemWb32bits);


	branch.jumpIn(exMem_branch);
	branch.addressIn(Mem_Branch2);
	branch.answerOut(branch_muxPC);

	//LA CAHE L1 DEL PROCESADOR
	data_memory.addressIn(exMem_dataMemoryAddress);
	data_memory.write_dataIn(exMem_dataMemoryData);
	data_memory.read_dataOut(dataMemory_MemWb);
	//LAS BANDERAS QUE PROVIENEN DE LA UNIDAD DE CONTROL
	//ESTA HABILITA LECTUTA DESDE LA MEMORIA
	data_memory.readIn(Mem_MemRead2);
	//ESTA HABILITA ESCRITUTRA HACIA LA MEMORIA
	data_memory.writeIn(Mem_MemWrite2);

	//CONENCTAMOS LAS SALIDAS DE "data_memory" AL TESTBENCH
	Testbench.addressIn(exMem_dataMemoryAddress);
	Testbench.write_dataIn(exMem_dataMemoryData);
	Testbench.readIn(Mem_MemRead2);
	Testbench.writeIn(Mem_MemWrite2);
	Testbench.read_dataOut(dataMemory_MemWb);

	//CONECTAMOS LAS SEÑALES DE CONTROL QUE VIENEN DESDE ex_mem A LOS CABLES DE ENTRADA DEL REGISTRO mem_wb
	mem_wb.Wb_MemtoRegIn(Wb_MemtoReg2);
	mem_wb.dir_In(exMem_MemWb);
	mem_wb.Wb_RegWriteIn(Wb_RegWrite2);

	mem_wb.memo_In[0](dataMemory_MemWb);
	mem_wb.memo_In[1](exMem_MemWb32bits);
	//========================================================================================
	// CABLES DE UNIDAD DE CONTROL FASE Mem-WB

	sc_signal<bool> Wb_MemtoReg3 ;
	sc_signal<sc_int<32>> MemWb_muxWb1, MemWb_muxWb2;

	Mux muxWB("muxWB");

	//CONECTAMOS LOS CABLES NECESARIOS A LAS SALIDAS DEL REGISTRO ex_mem PARA TRANSMITIR LAS SEÑALES DE CONTROL
	mem_wb.Wb_MemtoRegOut(Wb_MemtoReg3);
	mem_wb.Wb_RegWriteOut(reg_write);
	mem_wb.memo_Out[0](MemWb_muxWb1);
	mem_wb.memo_Out[1](MemWb_muxWb2);
	mem_wb.dir_Out(MemWb_register);

	muxWB.sIn(Wb_MemtoReg3);
	muxWB.aIn(MemWb_muxWb1);
	muxWB.bIn(MemWb_muxWb2);
	muxWB.cOut(muxWB_register);

	//CONENCTAMOS LAS SALIDAS DEL "muxWB"(MULTIPLEXOR DE LA FASE WB) AL TESTBENCH
	Testbench.sIn(Wb_MemtoReg3);
	Testbench.aIn(MemWb_muxWb1);
	Testbench.bIn(MemWb_muxWb2);
	Testbench.cOut(muxWB_register);

	//CONECTAMOS LOS EL RELOJ A LOS DIFERENTES MODULOS QUE LO NECESITAN
	Testbench.clk(clock);
	Unidad_Control.clk(clock);
	InstructionMemory.clk(clock);
	Imm_Gen.clk(clock);
	alu_control.clk(clock);
	branch.clk(clock);

	PC.clk(clock);
	File.clk(clock);
	alu.clk(clock);
	data_memory.clkIn(clock);

	IF_ID.clk(clock);
	id_ex.clkIn(clock);
	ex_mem.clkIn(clock);
	mem_wb.clkIn(clock);

	

	sc_start();

	return 0;
}