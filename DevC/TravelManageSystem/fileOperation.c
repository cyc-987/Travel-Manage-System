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
    int itemNum;
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
    fp = fopen("data","w+");
    if(fp == NULL){
        Log("file failed to save");
        return 1;
        }//save file failed

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

travelItem* createItem(int ID, Date startDate, Date endDate, double price, 
                int numberReserved, int numberTotal, bool isReserved,
                double rate, char* keyword, char* detail)
{
    travelItem *temp;
    temp = (travelItem*)malloc(sizeof(travelItem));
    temp->ID = ID;
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