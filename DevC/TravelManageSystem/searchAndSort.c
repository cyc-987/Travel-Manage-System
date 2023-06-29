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
        //Log("add item(id)");
    }
    return Head;
}


travelItem* searchByKeyword(travelItem *itemToBeSearched, char* keyword)
{
    if(itemToBeSearched == NULL) return NULL;  
    char* lowwerKeyword = upperToLower(keyword);
    //Log(lowwerKeyword);
    travelItem* head = itemToBeSearched;

    char temp1[100],temp2[100],temp3[100];
    travelItem* resultHead = NULL;
    travelItem* resultTemp = resultHead;
    travelItem* temp;
    //Log("tp");
    while(head != NULL){
        strcpy(temp1,head->name);
        strcpy(temp2,head->keyword);
        strcpy(temp3,head->detail);
        strcpy(temp1, upperToLower(temp1));
        //Log(temp1);
        strcpy(temp2, upperToLower(temp2));
        strcpy(temp3, upperToLower(temp3));
        if(strstr(temp1,lowwerKeyword) != NULL | 
        strstr(temp2,lowwerKeyword) != NULL |
        strstr(temp3,lowwerKeyword) != NULL){
            Log("find one result");
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
    char *word;
    word = (char*)malloc(sizeof(char*)*150);
    strcpy(word,toBeConvert);
    char* temp = word;
    while(*temp != '\0'){
        *temp = tolower(*temp);
        temp++;
    }
    *temp = '\0';
    return word;
}

travelItem* normalInsertByPrice(travelItem *Head, travelItem *itemToBeInsert)
{
    travelItem *ptr, *ptr1, *ptr2;

    ptr2 = Head;
    ptr = itemToBeInsert;

    if(Head == NULL){
        Head = ptr;
        Head->nextItem = NULL;
    }else{
        while((ptr->price>ptr2->price) && (ptr2->nextItem != NULL)){
            ptr1 = ptr2;
            ptr2 = ptr2->nextItem;
        } 
        if(ptr->price<=ptr2->price){
            if(Head == ptr2) Head = ptr;
            else ptr1->nextItem = ptr;
            ptr->nextItem = ptr2;
        }else{
            ptr2->nextItem = ptr;
            ptr->nextItem = NULL;
        }
        //Log("add item(price)");
    }

    return Head;
}

travelItem* sort(travelItem * itemToBeSortHead, travelItem*(*func)(travelItem *Head, travelItem *itemToBeInsert))
{
    travelItem *temp,*head,*temp2;
    if(itemToBeSortHead == NULL){
        return NULL;
    }else{
        head = createEmptyItem();
        itemCopy(head,itemToBeSortHead,itemToBeSortHead->ID);
        temp2 = itemToBeSortHead;
        temp2 = temp2->nextItem;
    }

    while(temp2 != NULL){
        temp = createEmptyItem();
        itemCopy(temp,temp2,temp2->ID);
        head = func(head,temp);
        temp2 = temp2->nextItem;
    }
    return head;
}

travelItem* normalInsertByRate(travelItem *Head, travelItem *itemToBeInsert)
{
    travelItem *ptr, *ptr1, *ptr2;

    ptr2 = Head;
    ptr = itemToBeInsert;

    if(Head == NULL){
        Head = ptr;
        Head->nextItem = NULL;
    }else{
        while((ptr->score>ptr2->score) && (ptr2->nextItem != NULL)){
            ptr1 = ptr2;
            ptr2 = ptr2->nextItem;
        } 
        if(ptr->score<=ptr2->score){
            if(Head == ptr2) Head = ptr;
            else ptr1->nextItem = ptr;
            ptr->nextItem = ptr2;
        }else{
            ptr2->nextItem = ptr;
            ptr->nextItem = NULL;
        }
    }

    return Head;
}