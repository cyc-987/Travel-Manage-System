#include "myHeader.h"

#ifndef _SEARCH_AND_SORT_H_
#define _SEARCH_AND_SORT_H_

//a midtern func used by "sortByID"
travelItem* normalInsertByID(travelItem *Head, travelItem *itemToBeInsert);

//sort the linked list by its ID
travelItem* sortByID(travelItem * itemToBeSortHead);


#endif