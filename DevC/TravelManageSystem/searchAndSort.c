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