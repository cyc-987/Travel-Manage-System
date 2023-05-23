#include "myHeader.h"

#ifndef _SEARCH_AND_SORT_H_
#define _SEARCH_AND_SORT_H_

//these are three functions tobe insert to "sort" function
travelItem* normalInsertByID(travelItem *Head, travelItem *itemToBeInsert);
travelItem* normalInsertByPrice(travelItem *Head, travelItem *itemToBeInsert);
travelItem* normalInsertByRate(travelItem *Head, travelItem *itemToBeInsert);

//a multifunc sort function
travelItem* sort(travelItem * itemToBeSortHead, travelItem*(*func)(travelItem *Head, travelItem *itemToBeInsert));

//search the keyword in "name", "keyword" and "details"
//dont need to worry about upper and lowwer characters
//special characters such as space and tab may still be taken into consideration
travelItem* searchByKeyword(travelItem *itemToBeSearched, char* keyword);

//convert all upper characters into lower form
char* upperToLower(char* toBeConvert);

#endif