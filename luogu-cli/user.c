#include <stdio.h>
#include <stdlib.h>

int crsf(char *a){
  system("curl https://www.luogu.com.cn | grep csrf > /tmp/luogu-cli.txt");
  FILE *te=fopen("/tmp/luogu-cli.txt","r");
  if(te==NULL){
    return -1;
  }
  char *buf=malloc(10000);
  fscanf(te,"%s",buf);
  fscanf(te,"%s",buf);
  fscanf(te,"%s",buf);
  int tt=9;//read the response of it and you will know why it is this
  int nowi=0;
  while(buf[tt]!='\"'){
    a[nowi++]=buf[tt];
    tt++;
  }
  a[nowi]='\0';
  free(buf);
  return 0;
}

int login(){
  return -1;
}
