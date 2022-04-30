#include "branch.h"


branch::branch(sc_module_name nm) : sc_module(nm) {
  th = 0;
  for(int i = 0; i < 2 ; i++){
    for(int j = 0 ; j < 30; j++){
      menu[i][j] = -1;
    }
  }
  SC_METHOD(operation);
  sensitive << clkIn;
}

void branch::operation() {
  int help = addressIn.read(), pos = th;
  int flag = true;
  for(int i = 0; i < 30; i++){
    if(menu[0][i] == help){
      flag = false;
      pos = i;
      if(jumpIn.read()){
        menu[1][i] += 1;
        if(menu[1][i] > 4){
          menu[1][i] = 4;
        }
      }else{
        menu[1][i] += 1;
        if(menu[1][i] < 0){
          menu[1][i] = 0;
        }        
      }
      break;
    }
  }

  if(flag){
    menu[0][pos] = help;
    menu[1][pos] = 1;

  }
  if(menu[1][pos] == 4){
    answerOut.write(true);
  }else{
     answerOut.write(false);   
  }
  if(flag){
    th += 1;
    if(th >= 30){
      th = 0;
    }
  }
}
