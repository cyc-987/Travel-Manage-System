#include "myHeader.h"

#ifndef _SEARCH_AND_SORT_H_
#define _SEARCH_AND_SORT_H_

//a midtern func used by "sortByID"
travelItem* normalInsertByID(travelItem *Head, travelItem *itemToBeInsert);

//sort the linked list by its ID
travelItem* sortByID(travelItem * itemToBeSortHead);

//search the keyword in "name", "keyword" and "details"
//dont need to worry about upper and lowwer characters
//special characters such as space and tab may still be taken into consideration
travelItem* searchByKeyword(travelItem *itemToBeSearched, char* keyword);

//convert all upper characters into lower form
char* upperToLower(char* toBeConvert);

#endif