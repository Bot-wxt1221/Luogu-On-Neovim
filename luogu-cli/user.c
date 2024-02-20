#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int readconf(char *cli,char *uid){
  char *buf3=getenv("HOME");
  char *buf4=malloc(1000);
  sprintf(buf4,
          "%s/.config/luogu-cli/cli.txt",buf3);
  FILE *te=fopen(buf4,"r");
  if(te==NULL){
    return -1;
  }
  int ret=0;
  ret=fscanf(te,"%s",cli);
  if(ret==-1){
    return ret;
  }
  fclose(te);
  sprintf(buf4,
          "%s/.config/luogu-cli/uid.txt",buf3);
  FILE *te2=fopen(buf4,"r");
  if(te2==NULL){
    return -1;
  }
  ret=fscanf(te2,"%s",uid);
  if(ret==-1){
    return ret;
  }
  fclose(te2);
  free(buf4);
  return 0;
}
int crsf(char *a){
  char *buf2=malloc(1000);
  char *cli=malloc(1000);
  char *uid=malloc(1000);
  readconf(cli,uid);
  sprintf(buf2,"curl https://www.luogu.com.cn --cookie \"__client_id=%s\" --cookie \"_uid=%s\"| grep csrf > /tmp/luogu-cli.txt",cli,uid);
  system(buf2);
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
  free(cli);
  free(uid);
  free(buf2);
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


