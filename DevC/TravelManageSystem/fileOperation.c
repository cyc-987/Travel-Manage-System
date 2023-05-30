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
        Log("file failed to open");
        return 1;//file is not existed
    }
    
    Log("file opened successfully"); 

    fileHead *FileHeadTemp = (fileHead*)malloc(sizeof(fileHead));
    fread(FileHeadTemp,sizeof(fileHead),1,fp);
    FileHead = FileHeadTemp;
    itemNum = FileHead->num;

    Log("file head read successfully");

    travelItem *temp1,*temp2;
    int count;
    unsigned int itemStructSize;
    itemStructSize = sizeof(travelItem);
    itemHead = temp1 = temp2 = NULL;
    for(count = 1;count<=itemNum;count++){
        temp1 = (travelItem*)malloc(itemStructSize);
        fread(temp1,itemStructSize,1,fp);
        Log("read one piece of data.");
        if(count == 1){
            itemHead = temp1;
        }else{
            temp2->nextItem = temp1;
        }
        temp2 = temp1;
        if(count == itemNum) temp2->nextItem = NULL;
    }

    Log("main data read completed");

    fclose(fp);
    Log("file closed successfully");
    return 0;
}

int saveFile()
{
    FILE *fp;
    fp = fopen("data","wb");
    if(fp == NULL){
        Log("file failed to save");
        return 1;
        }//save file failed

    if(FileHead == NULL){
        FileHead = (fileHead*)malloc(sizeof(fileHead));
        FileHead->num = itemNum;
    }else{
        FileHead->num = itemNum;
    }
    fwrite(FileHead,sizeof(fileHead),1,fp);
    Log("write filehead");
    int count;
    travelItem *temp = itemHead;
    unsigned int itemStructSize;
    itemStructSize = sizeof(travelItem);
    for(count = 1;count<=itemNum;count++){
        fwrite(temp,itemStructSize,1,fp);
        Log("write one piece of data.");
        temp = temp->nextItem;
    }

    fclose(fp);
    return 0;
}

travelItem* createItem(int ID, char* name, Date startDate, Date endDate, double price, 
                int numberReserved, int numberTotal, bool isReserved,
                double rate, char* keyword, char* detail)
{
    travelItem *temp;
    temp = (travelItem*)malloc(sizeof(travelItem));
    temp->ID = ID;
    strcpy(temp->name,name);
    temp->startDate = startDate;
    temp->endDate = endDate;
    temp->price = price;
    temp->numberReserved = numberReserved;
    temp->numberTotal = numberTotal;
    temp->isReserved = isReserved;
    temp->rate = rate;
    strcpy(temp->keyword,keyword);
    strcpy(temp->detail,detail);
    temp->nextItem = NULL;

    Log("created a new travelItem successfully");

    return temp;
}

int addItem(travelItem *itemToAdd)
{
    travelItem *ptr;
    ptr = NULL;
    if(itemHead == NULL){
        itemHead = itemToAdd;
        itemHead->nextItem = NULL;
    }else{
        ptr = itemHead;
        while(ptr->nextItem != NULL){
            if(ptr->ID == itemToAdd->ID){
                Log("failed to add the item: id conflicted");
                return 1;
            }
            ptr = ptr->nextItem;
        }
        ptr->nextItem = itemToAdd;
    }
    itemNum++;

    Log("item added successfully");

    return 0;
}

int deleteItem(travelItem *itemToDelete)
{
    travelItem *ptr1, *ptr2;

    while(itemHead != NULL && itemHead->ID == itemToDelete->ID){
        ptr2 = itemHead;
        itemHead = itemHead->nextItem;
        free(ptr2);
    }
    if(itemHead == NULL)return 0;

    ptr1 = itemHead;
    ptr2 = itemHead->nextItem;
    while(ptr2 != NULL){
        if(ptr2->ID == itemToDelete->ID){
            ptr1->nextItem = ptr2->nextItem;
            free(ptr2);
        }else{
            ptr1 = ptr2;
            ptr2 = ptr1->nextItem;
        }
    }
    itemNum--;

    Log("item deleted successfully");

    return 0;
}

void itemCopy(travelItem *copy, travelItem *toBeCopy, int ID)
{
    if(toBeCopy == NULL)copy = NULL;

    copy->ID = ID;
    strcpy(copy->name, toBeCopy->name);
    copy->startDate = toBeCopy->startDate;
    copy->endDate = toBeCopy->endDate;
    copy->price = toBeCopy->price;
    copy->numberReserved = toBeCopy->numberReserved;
    copy->numberTotal = toBeCopy->numberTotal;
    copy->isReserved = toBeCopy->isReserved;
    copy->rate = toBeCopy->rate;
    strcpy(copy->keyword,toBeCopy->keyword);
    strcpy(copy->detail,toBeCopy->detail);
    copy->nextItem = NULL;
}

travelItem* createEmptyItem()
{
    travelItem *temp;
    temp = (travelItem*)malloc(sizeof(travelItem));
    temp->ID = 0;
    strcpy(temp->name,"");
    Date tempDate = {2023,0,0};
    temp->startDate = tempDate;
    temp->endDate = tempDate;
    temp->price = 0;
    temp->numberReserved = 0;
    temp->numberTotal = 0;
    temp->isReserved = FALSE;
    temp->rate = 0;
    strcpy(temp->keyword,"");
    strcpy(temp->detail,"");
    temp->nextItem = NULL;
    return temp;
}

void outputFile(travelItem *itemToBeOutput)
{
    FILE *fp;
    fp = fopen("output.csv","w");
    if(fp == NULL){
        Log("file failed to output");
        return;
        }//output file failed
    
    travelItem *temp = itemToBeOutput;
    fprintf(fp,"ID,name,startDate,endDate,price,rate,numberReserved,numberTotal,isReserved,rate,keyword,detail");
    fprintf(fp,"\n");
    while(temp != NULL){
        fprintf(fp,"%d,%s,%d-%d-%d,%d-%d-%d,%.2f,%.2f,%d,%d,%d,%s,%s\n",
        temp->ID,temp->name,temp->startDate.year,temp->startDate.month,temp->startDate.date,
        temp->endDate.year,temp->endDate.month,temp->endDate.date,
        temp->price,temp->score,temp->numberReserved,temp->numberTotal,
        temp->isReserved,temp->keyword,temp->detail);

        temp = temp->nextItem;
    }

    fclose(fp);
}