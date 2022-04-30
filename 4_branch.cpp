#include "4_branch.h"

Branch::Branch(sc_module_name nm) : sc_module(nm) {
 
  SC_METHOD(operation);
  sensitive << jumpIn<< addressIn;
}

void Branch::operation() {
	if (jumpIn.read() and addressIn.read())	std::cout << "\n\n\n\n\nAqui hay un salto\n\n\n\n";
	
 answerOut.write(jumpIn.read() and addressIn.read());
}
