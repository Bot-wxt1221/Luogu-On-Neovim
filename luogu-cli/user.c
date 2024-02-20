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
  fclose(te);
  return 0;
}

int login(char *cli,char *uid){
  printf("uid:");
  scanf("%s",uid);
  printf("\ncli:");
  scanf("%s",cli);
  return 0;
}

int readconf(char *cli,char *uid){
  char *buf1=malloc(10000);
  char *buf2=malloc(10000);
  FILE *te=fopen("~/.config/luogu-cli/cli.txt","r");
  if(te==NULL){
    return -1;
  }
  fscanf(te,"%s",buf1);
  fclose(te);
  te=fopen("~/.config/luogu-cli/uid.txt","r");
  if(te==NULL){
    return -1;
  }
  fprintf(te,"%s",buf2);
  fclose(te);
  free(buf1);
  free(buf2);
  return 0;
}
