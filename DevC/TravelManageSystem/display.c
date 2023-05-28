#include "myHeader.h"

void initDisplay(int status)
{
    DisplayClear();
    if(status == 0)
    {
        drawBasicWindow(status);
        drawMainWindow();
        drawSideWindow(sidebarStatus);
        drawDatabase(0 , page);
    }else if(status == 1)
    {
        drawBasicWindow(status);
        drawMainWindow();
        //Log("test point");
        drawSideWindow(sidebarStatus);
        //Log("test point");
        drawDatabase(1 , page);
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
}

void drawDatabase(int status, int page){
    int i = 1;
    int oldNum = (page-1)*5;
    if (status==0){
		drawTextMiddle(0, 8, 0, 5.2, "No more data.");
	}else if(status==1){
		if( oldNum+1 <= itemNum ){ 
	        while( oldNum+i <= itemNum && i<=5){
                //Log("test point");
	            drawRow(oldNum+i, 5.2-i*0.8, 6-i*0.8, i);
                //Log("test point");
	            i++;
	        };
	    }else if(oldNum >= itemNum){
	        drawTextMiddle(0, 8, 0, 5.2, "No more data.");
	        return;
	    }
    }
}

void drawRow(int id, double y1, double y2, int labelNum){
    travelItem *ptr;
    ptr = goThrough(id);
    char *number[100];
    sprintf(number, "%d", labelNum);
    drawTextMiddle(0.2, 0.6, y1, y2, number);
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
    }else if(status == 1 | status == 2){
        /*drawDetails(ID)*/
        drawButton(9.1, 0.3, 1.8, 0.4, "Reserve", 0, 0, "");
    }else if(status == 3){
        clearSideWindow();
        drawInsert(currentItem);

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
    static char sdy[5] = "2023",sdm[3] = "",sdd[3] = "",edy[5] = "2023",edm[3] = "",edd[3] = "";

    //draw input
    textbox(GenUIID(0), 8, 4.5, 4, 1, item->name, sizeof(item->name));
    SetPenColor("Black");
    char to[3] = "to";
    drawTextMiddle(9.75,10.25,4.0,4.5,to); 
    if(textbox(GenUIID(0), 8.25, 4.0, 0.85, 0.5, sdy, sizeof(sdy))){
        item->startDate.year = atoi(sdy);
    }
    SetPenColor("Black");
    drawTextMiddle(8.25+0.85,8.25+0.85+0.1,4.0,4.5,"-");
    if(textbox(GenUIID(0), 9.2, 4.0, 0.25, 0.5, sdm, 3)){
        item->startDate.month = atoi(sdm);
    }
    //Log("debug");
    SetPenColor("Black");
    drawTextMiddle(9.4,9.5,4.0,4.5,"-");
    if(textbox(GenUIID(0), 9.5, 4.0, 0.25, 0.5, sdd, 3)){
        item->startDate.date = atoi(sdd);
    }
    

    if(textbox(GenUIID(0), 10.25, 4.0, 0.85, 0.5, edy, 5)){
        item->startDate.year = atoi(edy);
    }
    SetPenColor("Black");
    drawTextMiddle(10.25+0.85,10.25+0.85+0.1,4.0,4.5,"-");
    if(textbox(GenUIID(0), 11.25, 4.0, 0.25, 0.5, edm, 3)){
        item->startDate.month = atoi(edm);
    }
    SetPenColor("Black");
    drawTextMiddle(11.45,11.55,4.0,4.5,"-");
    if(textbox(GenUIID(0), 11.55, 4.0, 0.25, 0.5, edd, 3)){
        item->startDate.date = atoi(edd);
    }

    static char price[10] = "0";
    if(textbox(GenUIID(0), 8, 3.5, 4, 0.5, price, 10)){
        item->price = atof(price);
    }

    static char score[10] = "0";
    if(textbox(GenUIID(0), 8, 3.0, 4, 0.5, score, 10)){
        item->score = atof(score);
    }

    static char reserved[10] = "0";
    if(textbox(GenUIID(0), 8, 2.5, 1.75, 0.5, reserved, 10)){
        item->numberReserved = atoi(reserved);
    }
    SetPenColor("Black");
    drawTextMiddle(9.75,10.25,2.5,3.0,"//");
    static char total[10] = "0";
    if(textbox(GenUIID(0), 10.25, 2.5, 1.75, 0.5, total, 10)){
        item->numberTotal = atoi(total);
    }
    textbox(GenUIID(0), 8, 1.5, 4, 1, item->keyword, 50);
    //end of draw input

    //draw apply button
    SetPenColor("Black");
    drawButton(8.5, 0.3, 1, 0.4, "Apply", 0, 0, "White");
    drawButton(10.5, 0.3, 1, 0.4, "Cancel", 0, 0, "White");
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
    if(status == 0 | status == 1){
        drawMyMenuBar(status);
        
        //middle line
        MovePen(8,5.7);
        DrawLine(0,-5.7);
    }else if(status == 3){//insert mode
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
    MovePen(x,y);
    DrawTextString(label);
}
