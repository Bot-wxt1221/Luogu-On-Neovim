#include <stdio.h>
#include "command.h"
#include "user.h"
#include <stdlib.h>

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
  char *buf=malloc(10000);
  crsf(buf);
  printf("\ncrsf:%s\n",buf);
  free(buf);
  return 0;
}
