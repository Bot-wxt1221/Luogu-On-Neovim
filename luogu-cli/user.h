extern int login();

struct user{
   int uid;
   char cookie[MAX_COOKIE_SIZE];
};

extern int crsf(char *);

extern int login(char *,char *);

extern int readconf(char *,char *);
