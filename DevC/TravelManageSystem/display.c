#include "myHeader.h"

void initDisplay(int status)
{
    DisplayClear();
    lineIsActive[0] = lineIsActive[1] = lineIsActive[2] = lineIsActive[3] = lineIsActive[4] = 0;
    if(status == 0)
    {
        drawBasicWindow(status);
        drawMainWindow();
        drawSideWindow(sidebarStatus);
    }else if(status == 1)
    {
        drawBasicWindow(status);
        drawMainWindow();
        drawSideWindow(sidebarStatus);
        //Log("test point");
        if(sidebarStatus == 3){

        }
    }else if(status == 2){
        DisplayClear();
        drawBasicWindow(status);
        drawInsert(currentItem);
    }
}

void drawMainWindow()
{
    drawSearchBar();
    displayItem(currentHead,page);
}


void displayItem(travelItem* currentHead, int page)
{
    //draw the main area
    SetPenColor("Black");
    MovePen(0.5,1);
    DrawLine(7,0);
    DrawLine(0,4);
    DrawLine(-7,0);
    DrawLine(0,-4);

    SetPenColor("Gray");
    MovePen(0.5,4.2);
    DrawLine(7,0);
    MovePen(0.5,3.4);
    DrawLine(7,0);
    MovePen(0.5,2.6);
    DrawLine(7,0);
    MovePen(0.5,1.8);
    DrawLine(7,0);
    SetPenColor("Black");
    //end of draw main area

    //count for the items in current head
    int countItem = 0;
    travelItem* countTemp = currentHead;
    while(countTemp != NULL){
        countItem ++;
        countTemp = countTemp->nextItem;
    }
    MaxPage = countItem/5 + 1;

    //display the current data
    travelItem* head = currentHead;
    if(currentHead == NULL){
        drawTextMiddle(0.5,7.5,1,5,"Empty.");
    }else{
        int count = 1;
        //move the head to the current page
        while(count<page){
            int i;
            for(i=1;i<=5;i++){
                head = head->nextItem;
            }
            count++;
        }

        //draw the item of current page
        travelItem* relativePoint = head;
        int k = 0;
        lineIsActive[0] = lineIsActive[1] = lineIsActive[2] = lineIsActive[3] = lineIsActive[4] = 0;
        while(relativePoint != NULL && k<5){
            lineIsActive[k] = 1;
            drawSingleItem(relativePoint,k);
            k++;
            relativePoint = relativePoint->nextItem;
        }
    }
    //end of display

    //draw page operation button
    drawButton(5,0.2,1,0.6,"Pre Page",0,0,"White");
    drawButton(6.5,0.2,1,0.6,"Next Page",0,0,"White");
    char currentPage[20];
    sprintf(currentPage,"Current Page: %d/%d",page,MaxPage);
    drawTextMiddle(0.5,2,0,1,currentPage);
    //end of draw button
}

void drawSingleItem(travelItem* item, int relativeNum)
{
    char ID[10];
    sprintf(ID,"%d",item->ID);
    SetPenColor("Black");
    drawTextMiddle(0.5,1,(4.2-relativeNum*0.8),(5-relativeNum*0.8),ID);
    drawTextMiddle(1,2,4.2-relativeNum*0.8,5-relativeNum*0.8,item->name);
    char Date[20];
    sprintf(Date,"%d-%d-%d->%d-%d-%d",item->startDate.year,item->startDate.month,item->startDate.date,
    item->endDate.year,item->endDate.month,item->endDate.date);
    drawTextMiddle(2,3.5,4.2-relativeNum*0.8,5-relativeNum*0.8,Date);
    char price[10];
    sprintf(price,"$ %.2f",item->price);
    drawTextMiddle(3.5,4.5,4.2-relativeNum*0.8,5-relativeNum*0.8,price);
    char rate[10];
    sprintf(rate,"%.2f/5.0",item->score);
    drawTextMiddle(4.5,5.5,4.2-relativeNum*0.8,5-relativeNum*0.8,rate);
    char reserved[20];
    sprintf(reserved,"%d/%d reserved",item->numberReserved,item->numberTotal);
    drawTextMiddle(5.5,6.5,4.2-relativeNum*0.8,5-relativeNum*0.8,reserved);
    drawButton(6.6,4.4-relativeNum*0.8,0.8,0.4,"more info.",0,0,"White");
}



void drawSideWindow(int status)
{
    if(status == 0){
        drawTextMiddle(8,12,0,5.7,"Nothing to display.");
    }else if(status == 1 ){
        drawDetails(currentItem);
        if(currentItem->isReserved){
            drawButton(9.1, 0.3, 1.8, 0.4, "Unreserve", 0, 0, "White");
        }else{
            drawButton(9.1, 0.3, 1.8, 0.4, "Reserve", 0, 0, "White");
        }
    }else if(status == 2){
        drawDetails(currentItem);
        drawButton(9.1, 0.3, 1.8, 0.4, "Delete", 0, 0, "White");
    }
}

void clearSideWindow()
{
    drawButton(8, 0, 4, 5.7, "",1, 1,"White");
}

void drawInsert(travelItem* item)
{
    //Log("insert");

    //date temp
    static char sdy[5] = "",sdm[3] = "",sdd[3] = "",edy[5] = "",edm[3] = "",edd[3] = "";

    //draw input
    //id input
    SetPenColor("Black");
    drawLabel(0.5,5.1,"ID:"); 
    static char id[5] = "";
    if(textbox(GenUIID(0), 0.8, 5.0, 1, 0.5, id, sizeof(id))){
        item->ID = atoi(id);
    }

    //name input
    SetPenColor("Black");
    drawLabel(2.5,5.1,"Name:");
    //strcpy(item->name,"name");
    textbox(GenUIID(0), 3.0, 5.0, 2, 0.5, item->name, sizeof(item->name));

    //start date
    SetPenColor("Black");
    drawLabel(0.5,4.1,"Start Date:");
    if(textbox(GenUIID(0), 1.5, 4.0, 0.8, 0.4, sdy, sizeof(sdy))){
        item->startDate.year = atoi(sdy);
    }
    SetPenColor("Black");
    drawLabel(2.4,4.15,"--");
    if(textbox(GenUIID(0), 2.6, 4.0, 0.6, 0.4, sdm, sizeof(sdm))){
        item->startDate.month = atoi(sdm);
    }
    SetPenColor("Black");
    drawLabel(3.3,4.15,"--");
    if(textbox(GenUIID(0), 3.5, 4.0, 0.6, 0.4, sdd, sizeof(sdd))){
        item->startDate.date = atoi(sdd);
    }
    
    //end date
    SetPenColor("Black");
    drawLabel(0.5,3.1,"End Date:");
    if(textbox(GenUIID(0), 1.5, 3.0, 0.8, 0.4, edy, sizeof(edy))){
        item->endDate.year = atoi(edy);
    }
    SetPenColor("Black");
    drawLabel(2.4,3.15,"--");
    if(textbox(GenUIID(0), 2.6, 3.0, 0.6, 0.4, edm, sizeof(edm))){
        item->endDate.month = atoi(edm);
    }
    SetPenColor("Black");
    drawLabel(3.3,3.15,"--");
    if(textbox(GenUIID(0), 3.5, 3.0, 0.6, 0.4, edd, 3)){
        item->endDate.date = atoi(edd);
    }

    //price,etc
    SetPenColor("Black");
    drawLabel(0.5,2.1,"Price:");
    static char price[10] = "";
    if(textbox(GenUIID(0), 1.0, 2.0, 1.0, 0.4, price, sizeof(price))){
        item->price = atof(price);
    }

    SetPenColor("Black");
    drawLabel(2.8,2.1,"Rate:");
	static char score[10] = "";
    if(textbox(GenUIID(0), 3.3, 2.0, 1.0, 0.4, score, sizeof(score))){
        item->score = atof(score);
    }


    //reserved and total numbers
    SetPenColor("Black");
    drawLabel(0.5,1.1,"Reserved Number:");
    static char reserved[10] = "";
    if(textbox(GenUIID(0), 1.8, 1.0, 1, 0.4, reserved, sizeof(reserved))){
        item->numberReserved = atoi(reserved);
    }
    SetPenColor("Black");
    drawLabel(2.9,1.1," //    Total Number:");
    static char total[10] = "";
    if(textbox(GenUIID(0), 4.5, 1.0, 1, 0.4, total, sizeof(total))){
        item->numberTotal = atoi(total);
    }

    //keyword & detail
    SetPenColor("Black");
    drawLabel(6.5,4.6,"Keyword:");
    drawLabel(6.5,2.8,"Details:");
    //strcpy(item->keyword,"keyword");
    //strcpy(item->detail,"detail");
    textbox(GenUIID(0), 7.3, 4.5, 4, 1, item->keyword, sizeof(item->keyword));
    textbox(GenUIID(0), 7.3, 2.7, 4, 1, item->detail, sizeof(item->detail));
    //end of draw input

    //draw apply button
    SetPenColor("Black");
    drawButton(7.7, 1.2, 1, 0.4, "Apply", 0, 0, "White");
    drawButton(9.7, 1.2, 1, 0.4, "Cancel", 0, 0, "White");
}

void drawDetails(travelItem* currentItem)
{
    travelItem* ptr = currentItem;
    
    drawTextMiddle(8.0,12.0,4.5,5.5,ptr->name);
    char wholeDate[200];
    sprintf(wholeDate,"%d-%d-%d to %d-%d-%d", 
        ptr->startDate.year, ptr->startDate.month, ptr->startDate.date,
        ptr->endDate.year, ptr->endDate.month, ptr->endDate.date);   
    drawTextMiddle(8.0,12.0,4.0,4.5,wholeDate);
    char price[20];
    sprintf(price,"$ %.2f",ptr->price);
    drawTextMiddle(8.0,12.0,3.5,4.0,price);
    char score[20];
    sprintf(score,"%.2f/5 wondeful",ptr->score);
    drawTextMiddle(8.0,12.0,3.0,3.5,score);
    char number[50];
    sprintf(number,"%d//%d",ptr->numberReserved,ptr->numberTotal);
    drawTextMiddle(8.0,12.0,2.5,3.0,number);
    drawTextMiddle(8.0,12.0,2.0,2.5,ptr->keyword);
    drawTextMiddle(8.0,12.0,1.0,2.0,ptr->detail);
}

void drawSearchBar()
{
    MovePen(0,5.2);
    DrawLine(8,0);

    drawButton(6.1, 5.25, 0.8, 0.4, "Search",0,0,"");
    drawButton(7.1, 5.25, 0.8, 0.4, "Reset",0,0,"");

    //search box
    if(textbox(GenUIID(0), 0.5, 5.3, 2, 0.3, searchText, sizeof(searchText))){
        Log("detect change in search box");
    }
}

void drawBasicWindow(int status)
{
    if(status == 0 | status == 1){
        drawMyMenuBar(status);
        
        //middle line
        MovePen(8,5.7);
        DrawLine(0,-5.7);
    }else if(status == 2){//insert mode
        //draw nothing
    }

}

void drawMyMenuBar(int status)
{
    SetPenColor("Black");
    MovePen(0,5.7);
    DrawLine(12,0);
    MovePen(0,6);
    DrawLine(12,0);

    //draw menu list

    //draw usr
    if(status == 0){
        drawTextMiddle(10,12,5.7,6,"Current Usr: Customer");
    }else if(status == 1){
        drawTextMiddle(10,12,5.7,6,"Current Usr: Agency");
    }

    //left buttons
    drawButton(0, 5.7, 0.75, 0.3, "Refresh",0, 0,"White");
    drawButton(0.75, 5.7, 0.75, 0.3, "Save",0, 0,"White");
    drawButton(1.5, 5.7, 0.75, 0.3, "Change",0, 0,"White");

    //right buttons
    drawButton(9, 5.7, 0.75, 0.3, "Output",0, 0,"White");

    //special buttons
    if(systemStatus == 1 && sidebarStatus != 3){
        drawButton(2.25, 5.7, 0.75, 0.3, "Add",0, 0,"White");
    }
    

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
//    MovePen(x,y);
//    string name=label;
//    DrawTextString(name);
	drawLabel(x,y,label);
}

void refresh()
{
    MaxPage = itemNum/5 + 1;
    currentHead = itemHead;
    currentItem = currentHead;
    page = 1;
    lineIsActive[0] = lineIsActive[1] = lineIsActive[2] = lineIsActive[3] = lineIsActive[4] = 0;
    initDisplay(systemStatus);
}