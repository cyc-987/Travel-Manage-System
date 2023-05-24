#include "myHeader.h"

void initDisplay(int status)
{
    if(status == 0)
    {
        drawBasicWindow(status);
        drawMainWindow();
        drawSideWindow(0);
    }else if(status == 1)
    {
        drawSideWindow(1);
    }
}

void drawMainWindow()
{
    drawSearchBar();
}

void drawDatabase(int page){
    int i = 1;
    int oldNum = (page-1)*5;
    if( oldNum+1 <= itemNum ){ 
        while( oldNum+i <= itemNum && i<=5){
            drawRow(oldNum+i, 5.2-i*0.8, 6-i*0.8, i);
            i++;
        };
    }else if(oldNum >= itemNum){
        drawTextMiddle(0, 8, 0, 5.2, "No more data.");
        return;
    }
}

void drawRow(int id, double y1, double y2, int labelNum){
    travelItem *ptr;
    ptr = goThrough(id);
    drawTextMiddle(0.2, 0.6, y1, y2, labelNum+'0');
    drawTextMiddle(0.8, 3.6, y1, y2, ptr->name);
    char *wholeDate[200];
    sprintf(wholeDate,"%d-%d-%d to %d-%d-%d", 
        ptr->startDate.year, ptr->startDate.month, ptr->startDate.date,
        ptr->endDate.year, ptr->endDate.month, ptr->endDate.date);   
    drawTextMiddle(3.8, 5.8, y1, y2, wholeDate);
    char *price[100];
    sprintf(price, "%d $", ptr->price);
    drawTextMiddle(6, 6.8, y1, y2, price);
    drawButton(7, y1+0.2, 0.8, 0.4, "more infor.", 0 , 0, "");
}

travelItem* goThrough(int num){
    travelItem *ptr;
    ptr = itemHead;
    while (ptr != NULL)
    {
        if(ptr->ID == num)
            return ptr;
        ptr = ptr->nextItem;
    }

}

void drawSideWindow(int status)
{
    if(status == 0){
        drawTextMiddle(8,12,0,5.7,"Nothing to display.");
    }else if(status == 1){
        /*drawDetails(ID)*/
        drawButton(9.1, 0.3, 1.8, 0.4, "Reserve", 0, 0, "");
    }
}

void drawDetails(int id)
{
    travelItem *ptr;
    ptr = goThrough(id);
    drawTextMiddle(8.0,12.0,4.5,5.5,ptr->name);
    char *wholeDate[200];
    sprintf(wholeDate,"%d-%d-%d to %d-%d-%d", 
        ptr->startDate.year, ptr->startDate.month, ptr->startDate.date,
        ptr->endDate.year, ptr->endDate.month, ptr->endDate.date);
    drawTextMiddle(8.0,12.0,4.0,4.5,wholeDate);
    char *price[20];
    sprintf(price,"$%d",ptr->price);
    drawTextMiddle(8.0,12.0,3.5,4.0,price);
    char *score[50];
    sprintf(score,"%d/5 wondeful",ptr->score);
    drawTextMiddle(8.0,12.0,3.0,3.5,score);
    char *number[100];
    sprintf(number,"%d//%d",ptr->numberReserved,ptr->numberTotal);
    drawTextMiddle(8.0,12.0,2.5,3.0,number);
    drawTextMiddle(8.0,12.0,1.5,2.5,ptr->keyword);
}

void drawSearchBar()
{
    MovePen(0,5.2);
    DrawLine(8,0);

    drawButton(6.1, 5.25, 0.8, 0.4, "Search",0,0,"");
    drawButton(7.1, 5.25, 0.8, 0.4, "Reset",0,0,"");
}

void drawBasicWindow(int status)
{
    drawMyMenuBar(status);
    
    //middle line
    MovePen(8,5.7);
    DrawLine(0,-5.7);
}

void drawMyMenuBar(int status)
{
    SetPenColor("Black");
    MovePen(0,5.7);
    DrawLine(12,0);
    MovePen(0,6);
    DrawLine(12,0);

    //draw menu list

}

void drawButton(double startX, double startY, double w, double h, char* label,int isFilled, double density, char* fillColor)
{   
    if(isFilled == 1) 
    {
        SetPenColor(fillColor);
        StartFilledRegion(density);
        drawSquare(startX,startY,w,h);
        EndFilledRegion();
        SetPenColor("Black");
    }
    drawSquare(startX,startY,w,h);
    drawTextMiddle(startX,startX+w,startY,startY+h,label);
}

void drawTextMiddle(double x1, double x2, double y1, double y2, char* label)
{
    double widthOfText = TextStringWidth(label);
    double heightOfText = GetFontHeight();
    double x,y;
    x = x1 + (fabs(x1-x2)-widthOfText)/2;
    y = y1 + (fabs(y1-y2)-heightOfText)/2 + 0.03;
    MovePen(x,y);
    DrawTextString(label);
}
