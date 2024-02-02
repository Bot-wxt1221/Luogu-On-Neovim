#include <stdio.h>
#include "command.h"
#include "user.h"

int main(int argc,char *argv[]){
  if(argc==1){
    help();
    goto end;
  }
  switch(argv[1][0]){
    case 'h':{
      help();
      goto end;
    }
    case 'l':{
      login();
      break;
    }
  }
  end:{}
  return 0;
}
