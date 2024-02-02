#include "user.h"
#include <stdio.h>
#define NO_CONFIG_FILE_ERROR -1
#define FILE_CONTENT_ERROR -2
#define CONFIG_WRITE_ERROR -3

int getUser(struct user *in){
  FILE *fp=NULL;
  fp=fopen("~/.config/LuoguCLI/config.txt","r");
  if(ferror(fp)){
    return NO_CONFIG_FILE_ERROR;
  }
  int ret=fscanf(fp,"%d",&in->uid);
  if(ret==EOF||ferror(fp)){
    return FILE_CONTENT_ERROR;
  }
  ret=fscanf(fp,"%s",in->cookie);
  if(ret==EOF||ferror(fp)){
    return FILE_CONTENT_ERROR;
  }
  return 0;
}

int saveUser(struct user in){
  FILE *fp=NULL;
  fp=fopen("~/.config/LuoguCLI/config.txt","w+");
  if(ferror(fp)){
    return CONFIG_WRITE_ERROR;
  }
  int ret=printf("%d\n%s\n",in.uid,in.cookie);
  return ret;
}


