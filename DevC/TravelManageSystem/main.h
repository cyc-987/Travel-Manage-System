#include "myHeader.h"

#ifndef _MAIN_H_
#define _MAIN_H_

typedef struct Date
{
    int year;
    int month;
    int date;
}Date;


//#pragma pack(1)
typedef struct travelItem{
    int ID;

    char name[50];
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
//#pragma pack()

//#pragma pack(1)
typedef struct fileHead{
    int num;
}fileHead;
//#pragma pack()

extern int systemStatus;
extern int sidebarStatus;
extern bool isLog;
extern int itemNum;
extern travelItem *itemHead;
extern fileHead *FileHead;
extern travelItem *currentHead;
extern travelItem *currentItem;
extern page;
extern char searchText[100];
extern int MaxPage;
extern bool lineIsActive[5];







#endif
