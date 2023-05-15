#include "myHeader.h"

void Log(string content)
{
    if(isLog){
        FILE *fp = NULL;
        fp = fopen("log.txt","a");
        fprintf(fp,"%s\n",content);
        fclose(fp);
    }
    else return;
}
