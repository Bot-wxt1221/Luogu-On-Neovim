#include <stdio.h>
#include "command.h"
#include "user.h"
#include <stdlib.h>
#include "problem.h"

int main(int argc,char *argv[]){
  int ret=0;
  if(argc==1){
    ret=help();
    goto end;
  }
  char *buf3=getenv("HOME");
  char *buf4=malloc(1000);
  sprintf(buf4,
          "%s/.config/luogu-cli/cli.txt",buf3);
  FILE *te=fopen(buf4,"r");
  if(te==NULL){
    system("mkdir ~/.config/luogu-cli");
    system("touch ~/.config/luogu-cli/a.txt");
  } 
 switch(argv[1][0]){
  case 'h':{
    ret=help();
    goto end;
  }
  case 'l':{
    char *buf1=malloc(1000);
    char *buf2=malloc(1000);
    char *buf3=getenv("HOME");
    char *buf4=malloc(1000);
    ret=login(buf1,buf2);
    sprintf(buf4,
            "%s/.config/luogu-cli/cli.txt",buf3);
    FILE *te=fopen(buf4,"w");
    if(te==NULL){
      printf("File error");
      return -1;
    }
    fprintf(te,"%s",buf1);
    fclose(te);
    sprintf(buf4,
            "%s/.config/luogu-cli/uid.txt",buf3);
    te=fopen(buf4,"w");
    if(te==NULL){
      printf("File error");
      return -1;
    }
    fprintf(te,"%s",buf2);
    fclose(te);
    free(buf1);
    free(buf4);
    free(buf2);
    break;
  }
  case 's':{
    ret=submit(argv[2],argv[3]);
    break;
  }
  }
  end:{}
  return ret;
}
