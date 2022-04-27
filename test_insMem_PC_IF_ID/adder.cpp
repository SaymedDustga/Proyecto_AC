#include "adder.h"

Adder::Adder(sc_module_name nm) : sc_module(nm), number_1In("number_1In"), number_2In("number_2In"), resultOut("resultOut"), clk("clk")
{
	SC_THREAD(operation);
	sensitive << clk.neg();
	std::cout << "\nadder" << endl;
}

void Adder::operation()
{
	bool flag = true;
	while (flag)
	{
		int sum = number_1In.read();
		int sum_2 = number_2In.read();
		std ::cout << " \nmi ultimo resultado es:" << sum + sum_2 << endl;
		wait();
		wait();
//		wait();
//		wait();
		resultOut.write(sum + sum_2);
	}
}
