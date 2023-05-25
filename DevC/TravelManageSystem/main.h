#include "myHeader.h"

#ifndef _MAIN_H_
#define _MAIN_H_

typedef struct Date
{
    int year;
    int month;
    int date;
}Date;

typedef struct travelItem{
    int ID;

    char name[100];
    Date startDate;
    Date endDate;

    double price;
    double score;
    int numberReserved;
    int numberTotal;
    bool isReserved;
    double rate;

    char keyword[50];
    char detail[200];

    struct travelItem *nextItem;
}travelItem;

typedef struct fileHead{
    int num;
}fileHead;

extern int systemStatus;
extern bool isLog;
extern int itemNum;
extern travelItem *itemHead;
extern fileHead *FileHead;
extern travelItem *currentHead;
extern page;

enum buttonUid {searchButton,resetButton};
enum menuListUid {file};


#endif
