#include "Unidad_Control.h"


Unidad_Control::Unidad_Control(sc_module_name nm) : sc_module(nm) {
  SC_METHOD(operation);
  sensitive << clkIn;
}

	// 1 add
	// 2 sub
	// 3 addi
	// 4 sll
	// 5 srl
	// 6 slli
	// 7 srli
	// 8 lw
	// 9 sw
	// 10 and
	// 11 or
	// 12 andi
	// 13 ori
	// 14 beq
	// 15 bne
	// 16 jalr

void Unidad_Control::operation() {

  Ex_ALUOpOut.write(3);

  if(dir_In.read() == 1){
    read_writeOutOut.write(1);
    Men_MemReadOut.write(0);
    Men_MemWriteOut.write(0);
    Men_BranchOut.write(0);
    Ex_ALUSrcOut.write(0);
  }
  if(dir_In.read() == 2){
    read_writeOutOut.write(1);
    Men_MemReadOut.write(0);
    Men_MemWriteOut.write(0);
    Men_BranchOut.write(0);
    Ex_ALUSrcOut.write(0);
  }
  if(dir_In.read() == 3){
    read_writeOutOut.write(1);
    Men_MemReadOut.write(0);
    Men_MemWriteOut.write(0);
    Men_BranchOut.write(0);
    Ex_ALUSrcOut.write(1);
  }
  if(dir_In.read() == 4){
    read_writeOutOut.write(1);
    Men_MemReadOut.write(0);
    Men_MemWriteOut.write(0);
    Men_BranchOut.write(0);
    Ex_ALUSrcOut.write(0);
  }
  if(dir_In.read() == 5){
    read_writeOutOut.write(1);
    Men_MemReadOut.write(0);
    Men_MemWriteOut.write(0);
    Men_BranchOut.write(0);
    Ex_ALUSrcOut.write(0);
  }
  if(dir_In.read() == 6){
    read_writeOutOut.write(1);
    Men_MemReadOut.write(0);
    Men_MemWriteOut.write(0);
    Men_BranchOut.write(0);
   Ex_ALUSrcOut.write(1);
  }
  if(dir_In.read() == 7){
    read_writeOutOut.write(1);
    Men_MemReadOut.write(0);
    Men_MemWriteOut.write(0);
    Men_BranchOut.write(0);
    Ex_ALUSrcOut.write(1);
  }
  if(dir_In.read() == 8){
    read_writeOutOut.write(1);
    Men_MemReadOut.write(1);
    Men_MemWriteOut.write(0);
    Men_BranchOut.write(0);
    Wb_MemtoRegOut.write(1);
    Ex_ALUSrcOut.write(1);

  }else Wb_MemtoRegOut.write(0);
  if(dir_In.read() == 9){
    read_writeOutOut.write(0);
    Men_MemReadOut.write(0);
    Men_MemWriteOut.write(1);
    Men_BranchOut.write(0);
    Ex_ALUSrcOut.write(1);
  }
  if(dir_In.read() == 10){
    read_writeOutOut.write(1);
    Men_MemReadOut.write(0);
    Men_MemWriteOut.write(0);
    Men_BranchOut.write(0);
    Ex_ALUSrcOut.write(0);
  }
  if(dir_In.read() == 11){
    read_writeOutOut.write(1);
    Men_MemReadOut.write(0);
    Men_MemWriteOut.write(0);
    Men_BranchOut.write(0);
    Ex_ALUSrcOut.write(0);
  }
  if(dir_In.read() == 12){
    read_writeOutOut.write(1);
    Men_MemReadOut.write(0);
    Men_MemWriteOut.write(0);
    Men_BranchOut.write(0);
    Ex_ALUSrcOut.write(1);
  }
  if(dir_In.read() == 13){
    read_writeOutOut.write(1);
    Men_MemReadOut.write(0);
    Men_MemWriteOut.write(0);
    Men_BranchOut.write(0);
    Ex_ALUSrcOut.write(1);
  }
  if(dir_In.read() == 14){
    read_writeOutOut.write(0);
    Men_MemReadOut.write(0);
    Men_MemWriteOut.write(0);
    Men_BranchOut.write(1);
    Ex_ALUSrcOut.write(0);
  }
  if(dir_In.read() == 15){
    read_writeOutOut.write(0);
    Men_MemReadOut.write(0);
    Men_MemWriteOut.write(0);
    Men_BranchOut.write(1);
    Ex_ALUSrcOut.write(0);

  }
  if(dir_In.read() == 16){
    read_writeOutOut.write(0);
    Men_MemReadOut.write(0);
    Men_MemWriteOut.write(0);
    Men_BranchOut.write(1);
    Ex_ALUSrcOut.write(1);
  }


}
