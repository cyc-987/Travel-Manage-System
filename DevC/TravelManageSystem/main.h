#include "myHeader.h"

#ifndef _MAIN_H_
#define _MAIN_H_

extern int systemStatus;
extern bool isLog;

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
    int numberReserved;
    int numberTotal;
    bool isReserved;
    double rate;

    char keyword[50];
    char detail[200];
}


#endif