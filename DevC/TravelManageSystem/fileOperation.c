#include "myHeader.h"

void Log(string content)
{
    FILE *fp = NULL;
    fp = fopen("log.txt","a");
    fprintf(fp,content);
    fclose(fp);
}
