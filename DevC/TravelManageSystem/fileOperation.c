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

int openFile()
{
    FILE *fp;
    fp = fopen("data","rb");
    if(fp == NULL){
        FileHead = NULL;
        return 1;//file is not existed
    } 

    fread(FileHead,sizeof(fileHead),1,fp);
    int itemNum;
    itemNum = FileHead->num;

    travelItem *temp1,*temp2;
    int count;
    unsigned int itemStructSize;
    itemStructSize = sizeof(travelItem);
    itemHead = temp1 = temp2 = NULL;
    for(count = 1;count<=itemNum;count++){
        fread(temp1,itemStructSize,1,fp);
        if(count == 1){
            itemHead = temp1;
        }else{
            temp2->nextItem = temp1;
        }
        temp2 = temp1;
        if(count == itemNum) temp2->nextItem = NULL;
    }

    fclose(fp);
    return 0;
}

int saveFile(travelItem *itemHead,int itemNum)
{
    FILE *fp;
    fp = fopen("data","w+");
    if(fp == NULL)return 1;//save file failed

    fwrite(FileHead,sizeof(fileHead),itemNum,fp);
    int count;
    travelItem *temp = itemHead;
    unsigned int itemStructSize;
    itemStructSize = sizeof(travelItem);
    for(count = 1;count<=itemNum;count++){
        fwrite(temp,itemStructSize,1,fp);
        temp = temp->nextItem;
    }

    fclose(fp);
    return 0;
}