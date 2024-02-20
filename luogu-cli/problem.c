#include "user.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int submit(char *pro,char *code){
  char *uid=malloc(1000);
  char *cli=malloc(1000);
  char *buf=malloc(10000000);
  char *tok=malloc(100);
  readconf(cli,uid);
  crsf(tok);
  sprintf(buf,"curl --cookie \"__client_id=%s\" --cookie \"_uid=%s\" --user-agent \"Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/121.0.0.0 Safari/537.36 Edg/121.0.0.0\" -X POST  -H \"Content-Type: application/json\" -e \"https://www.luogu.com.cn/problem/%s\"  https://www.luogu.com.cn/fe/api/problem/submit/%s -d \'{\"enableO2\":1,\"lang\":28,\"code\":\"%s\"}\' -H \"X-Csrf-Token: %s\" > /tmp/luogu-cli.txt",cli,uid,pro,pro,code,tok);
  system(buf);
  FILE *fi=fopen("/tmp/luogu-cli.txt","r");
  if(fi==NULL){
    return -1;
  }
  fscanf(fi,"%s",buf);
  int i=7;
  long long rid=0;
  while('0'<=buf[i]&&buf[i]<='9'){
    rid=rid*10+buf[i]-'0';
    i++;
  }
  sprintf(buf,"microsoft-edge-stable https://www.luogu.com.cn/record/%lld",rid);
  system(buf);
  free(buf);
  free(tok);
  free(cli);
  free(uid);
  return 0;
}
