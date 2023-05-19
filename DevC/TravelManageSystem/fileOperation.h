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
travelItem* createItem(int ID, Date startDate, Date endDate, double price, 
                int numberReserved, int numberTotal, bool isReserved,
                double rate, char* keyword, char* detail);

#endif