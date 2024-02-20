#include "user.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int submit(char *pro,char *code){
  char *uid=malloc(1000);
  char *cli=malloc(1000);
  char *buf=malloc(10000000);
  readconf(cli,uid);
  sprintf(buf,"curl --cookie \"__client_id=%s\" --cookie \"_uid=%s\" --user-agent \"Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/121.0.0.0 Safari/537.36 Edg/121.0.0.0\" -X POST  -H \"Content-Type: application/json\" -e \"https://www.luogu.com.cn/problem/%s\"  https://www.luogu.com.cn/fe/api/problem/submit/%s  -v -d \'{\"enableO2\":1,\"lang\":28,\"code\":\"%s\"}\'",cli,uid,pro,pro,code);
  free(buf);
}
