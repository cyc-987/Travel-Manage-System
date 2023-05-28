#include "myHeader.h"
#ifndef _FILE_H_
#define _FILE_H_

//output debug information in log.txt
//eg. Log("this is a message");
void Log(string);

//open the data file in the directory, and load them into an linked list
//return 1 if the file failed to open
int openFile();

//save the current data into the data file, but not free the linked list
//return 1 if the file failed to save
int saveFile();

//add an item into the linked list
//return 1 if the id is conflicted, and will not be added
int addItem(travelItem*);

//delete an item from the linked list, judging by ID
int deleteItem(travelItem*);

//create an item based on the information given
//return the point of the item
travelItem* createItem(int ID, char* name, Date startDate, Date endDate, double price, 
                int numberReserved, int numberTotal, bool isReserved,
                double rate, char* keyword, char* detail);

//copy one item to another,but you need to set the ID
//caution:the next item is set as NULL by default
void itemCopy(travelItem *copy, travelItem *toBeCopy, int ID);

//create an empty item, but set the next item as NULL
travelItem* createEmptyItem();

//out put as csv file
void outputFile(travelItem *itemToBeOutput);

#endif