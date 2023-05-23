#include "myHeader.h"

travelItem* normalInsertByID(travelItem *Head, travelItem *itemToBeInsert)
{
    travelItem *ptr, *ptr1, *ptr2;

    ptr2 = Head;
    ptr = itemToBeInsert;

    if(Head == NULL){
        Head = ptr;
        Head->nextItem = NULL;
    }else{
        while((ptr->ID>ptr2->ID) && (ptr2->nextItem != NULL)){
            ptr1 = ptr2;
            ptr2 = ptr2->nextItem;
        } 
        if(ptr->ID<=ptr2->ID){
            if(Head == ptr2) Head = ptr;
            else ptr1->nextItem = ptr;
            ptr->nextItem = ptr2;
        }else{
            ptr2->nextItem = ptr;
            ptr->nextItem = NULL;
        }
    }
}

travelItem* sortByID(travelItem * itemToBeSortHead)
{
    travelItem *temp,*head,*temp2;
    if(itemToBeSortHead == NULL)return NULL;
    else{
        head = createEmptyItem();
        itemCopy(head,itemToBeSortHead,itemToBeSortHead->ID);
        temp2 = itemToBeSortHead;
        temp2 = temp2->nextItem;
    }

    while(temp2 != NULL){
        temp = createEmptyItem();
        itemCopy(temp,temp2,temp2->ID);
        normalInsertByID(head,temp);
        temp2 = temp2->nextItem;
    }
}

travelItem* searchByKeyword(travelItem *itemToBeSearched, char* keyword)
{
    if(itemToBeSearched == NULL) return NULL;
    char* lowwerKeyword = upperToLower(keyword);
    travelItem* head = itemToBeSearched;

    char *temp1,*temp2,*temp3;
    travelItem* resultHead = NULL;
    travelItem* resultTemp = resultHead;
    travelItem* temp;
    while(head->nextItem != NULL){
        temp1 = head->name;
        temp2 = head->keyword;
        temp3 = head->detail;
        temp1 = upperToLower(temp1);
        temp2 = upperToLower(temp2);
        temp3 = upperToLower(temp3);
        if(strstr(temp1,lowwerKeyword) != NULL | 
        strstr(temp2,lowwerKeyword) != NULL |
        strstr(temp3,lowwerKeyword) != NULL){
            if(resultHead == NULL){
                resultHead = createEmptyItem();
                itemCopy(resultHead,head,head->ID);
                resultTemp = resultHead;
            }else{
                temp = createEmptyItem();
                itemCopy(temp,head,head->ID);
                resultTemp->nextItem = temp;
                resultTemp = temp;
            }
        }
        head = head->nextItem;
    }
    return resultHead;
}

char* upperToLower(char* toBeConvert)
{
    char temp;
    char* result = (char*)malloc(sizeof(toBeConvert));
    result = NULL;
    char* resultTemp = result;
    char* toBeConvertTemp = toBeConvert;
    temp = *(toBeConvertTemp);
    while(temp != '\0'){
        temp = tolower(temp);
        *(resultTemp) = temp;
        resultTemp ++;
        toBeConvertTemp ++;
    }
    *(++resultTemp) = '\0';
    return result;
}