#include "myHeader.h"
#ifndef _FILE_H_
#define _FILE_H_

void Log(string);
int openFile();
int saveFile(travelItem *itemHead,int itemNum);
int addItem(travelItem);
int deleteItem(travelItem);
void creatItem(int ID, Date startDate, Date endDate, double price, 
                int numberReserved, int numberTotal, bool isReserved,
                double rate, char* keyword, char* detail);

#endif