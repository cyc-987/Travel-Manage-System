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
    }else if(status == 3){
        DisplayClear();
        drawBasicWindow(status);
        drawEdit(currentItem);
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
    }else if(status == 1 ){
        drawDetails(currentItem);
        drawButton(9.1, 0.3, 1.8, 0.4, "Reserve", 0, 0, "White");
    }else if(status == 2){
        drawDetails(currentItem);
        drawButton(9.1, 0.3, 1.8, 0.4, "Edit", 0, 0, "White");
    }else if(status == 3){
        clearSideWindow();
        drawInsert(currentItem);
    }
}

void clearSideWindow()
{
    drawButton(8, 0, 4, 5.7, "",1, 1,"White");
}

void drawEdit(travelItem* item)
{
    //date temp
    static char sdy[5] = "",sdm[3] = "",sdd[3] = "",edy[5] = "",edm[3] = "",edd[3] = "";
    itoa(item->startDate.year,sdy ,5);itoa(item->startDate.month,sdm ,3);
    itoa(item->startDate.date,sdd ,3);itoa(item->endDate.year,sdy ,5);
    itoa(item->endDate.month,sdm ,3);itoa(item->endDate.date,sdd ,3);

    //draw 
    //id
    SetPenColor("Black");
    drawLabel(0.5,5.1,"ID:"); 
    static char id[5] = "";
    itoa(item->ID,id,5);
    if(textbox(GenUIID(0), 0.8, 5.0, 1, 0.5, id, sizeof(id))){
        item->ID = atoi(id);
    }

    //name 
    SetPenColor("Black");
    drawLabel(2.5,5.1,"Name:");
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
        item->startDate.year = atoi(edy);
    }
    SetPenColor("Black");
    drawLabel(2.4,3.15,"--");
    if(textbox(GenUIID(0), 2.6, 3.0, 0.6, 0.4, edm, sizeof(edm))){
        item->startDate.month = atoi(edm);
    }
    SetPenColor("Black");
    drawLabel(3.3,3.15,"--");
    if(textbox(GenUIID(0), 3.5, 3.0, 0.6, 0.4, edd, 3)){
        item->startDate.date = atoi(edd);
    }

    //price
    SetPenColor("Black");
    drawLabel(0.5,2.1,"Price:");
    static char price[10] = "";
    sprintf(price ,"%5.2f",item->price);
    if(textbox(GenUIID(0), 1.0, 2.0, 1.0, 0.4, price, sizeof(price))){
        item->price = atof(price);
    }

    SetPenColor("Black");
    drawLabel(2.8,2.1,"Score:");
	static char score[10] = "";
    sprintf(score ,"%3.1f",item->score);
    if(textbox(GenUIID(0), 3.3, 2.0, 1.0, 0.4, score, sizeof(score))){
        item->score = atof(score);
    }

    //reserved and total numbers
    SetPenColor("Black");
    drawLabel(0.5,1.1,"Reserved Number:");
    static char reserved[10] = "";
    itoa(item->numberReserved,reserved,10);
    if(textbox(GenUIID(0), 1.8, 1.0, 1, 0.4, reserved, sizeof(reserved))){
        item->numberReserved = atoi(reserved);
    }
    SetPenColor("Black");
    drawLabel(2.9,1.1," //    Reserved Number:");
    static char total[10] = "";
    itoa(item->numberTotal,total,10);
    if(textbox(GenUIID(0), 4.5, 1.0, 1, 0.4, total, sizeof(total))){
        item->numberTotal = atoi(total);
    }

    //keyword & detail
    SetPenColor("Black");
    drawLabel(6.5,4.6,"Keyword:");
    drawLabel(6.5,2.8,"Details:");
    textbox(GenUIID(0), 7.3, 4.5, 4, 1, item->keyword, sizeof(item->keyword));
    textbox(GenUIID(0), 7.3, 2.7, 4, 1, item->detail, sizeof(item->detail));
    //end of draw edit

    //draw  button
    SetPenColor("Black");
    drawButton(7.7, 1.2, 1, 0.4, "Save", 0, 0, "White");
    drawButton(9.7, 1.2, 1, 0.4, "Delete", 0, 0, "White");
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
    strcpy(item->name,"name");
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
        item->startDate.year = atoi(edy);
    }
    SetPenColor("Black");
    drawLabel(2.4,3.15,"--");
    if(textbox(GenUIID(0), 2.6, 3.0, 0.6, 0.4, edm, sizeof(edm))){
        item->startDate.month = atoi(edm);
    }
    SetPenColor("Black");
    drawLabel(3.3,3.15,"--");
    if(textbox(GenUIID(0), 3.5, 3.0, 0.6, 0.4, edd, 3)){
        item->startDate.date = atoi(edd);
    }

    //price,etc
    SetPenColor("Black");
    drawLabel(0.5,2.1,"Price:");
    static char price[10] = "";
    if(textbox(GenUIID(0), 1.0, 2.0, 1.0, 0.4, price, sizeof(price))){
        item->price = atof(price);
    }

    SetPenColor("Black");
    drawLabel(2.8,2.1,"Score:");
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
    drawLabel(2.9,1.1," //    Reserved Number:");
    static char total[10] = "";
    if(textbox(GenUIID(0), 4.5, 1.0, 1, 0.4, total, sizeof(total))){
        item->numberTotal = atoi(total);
    }

    //keyword & detail
    SetPenColor("Black");
    drawLabel(6.5,4.6,"Keyword:");
    drawLabel(6.5,2.8,"Details:");
    strcpy(item->keyword,"keyword");
    strcpy(item->detail,"detail");
    textbox(GenUIID(0), 7.3, 4.5, 4, 1, item->keyword, sizeof(item->keyword));
    textbox(GenUIID(0), 7.3, 2.7, 4, 1, item->detail, sizeof(item->detail));
    //end of draw input

    //draw apply button
    SetPenColor("Black");
    drawButton(7.7, 1.2, 1, 0.4, "Apply", 0, 0, "White");
    drawButton(9.7, 1.2, 1, 0.4, "Cancel", 0, 0, "White");
}

void drawDetails(travelItem* item)
{
    travelItem *ptr=item;
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
    drawTextMiddle(8.0,12.0,2.0,2.5,ptr->keyword);
    drawTextMiddle(8.0,12.0,1.0,2.0,ptr->detail);
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
    MovePen(x,y);
    DrawTextString(label);
}

