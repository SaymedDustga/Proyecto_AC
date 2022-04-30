#include "5_MuxWB.h"

MuxWB::MuxWB(sc_module_name nm) : sc_module(nm)
{
	SC_METHOD(operation);
	sensitive << aIn << bIn << RegWriteIn;
}

void MuxWB::operation()
{
	if (RegWriteIn.read())
		cOut.write(bIn.read());
	else
		cOut.write(aIn.read());
}

MuxWB::~MuxWB() {}