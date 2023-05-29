#include "myHeader.h"

extern travelItem *itemHead;
extern bool isLog;
extern int systemStatus;
extern int sidebarStatus;
extern int itemNum;
extern travelItem *itemHead;
extern travelItem *currentItem;
extern travelItem *currentHead;
extern fileHead *FileHead;
extern int page;

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
                if(oldNum+i <= itemNum)
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
	SetPenColor("Black");
	
	//go through the list 
    travelItem *ptr;
    ptr = itemHead;
    int i=0;
    while (ptr != NULL && i<itemNum)
    {
    	i++;
        if(ptr->ID == id){
        	break;
		}
        else
			ptr = ptr->nextItem;
    }
    
    char number[10];
    sprintf(number, "%d", labelNum);
    drawTextMiddle(0.2, 0.6, y1, y2, number);
    
    char* name = ptr->name;
	drawTextMiddle(0.8, 2.8, y1, y2, name);
    
    char wholeDate[50];
    sprintf(wholeDate,"%d-%d-%d to %d-%d-%d", 
        ptr->startDate.year, ptr->startDate.month, ptr->startDate.date,
        ptr->endDate.year, ptr->endDate.month, ptr->endDate.date);   
	drawTextMiddle(3.0, 5.5, y1, y2, wholeDate);
    
    char price[10];
    sprintf(price, "%.2f $", ptr->price);
    drawTextMiddle(5.7, 6.5, y1, y2, price);
    
    drawButton(7, y1+0.2, 0.8, 0.4, "more infor.",0,0,"red");//can't interact 
    
    SetPenColor("Gray");
	MovePen(0,y1);
    DrawLine(8,0);
    
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
    static char sdy[5] = "sy",sdm[3] = "m",sdd[3] = "d",edy[5] = "ey",edm[3] = "m",edd[3] = "d";

    //draw input
    //id input
    static char id[5] = "ID";
    if(textbox(GenUIID(0), 0.5, 4.65, 1, 0.7, id, sizeof(id))){
        item->ID = atoi(id);
    }

    //name input
    strcpy(item->name,"name");
    textbox(GenUIID(0), 2.5, 4.65, 2, 0.7, item->name, sizeof(item->name));

    //start date
    if(textbox(GenUIID(0), 0.5, 3.65, 0.5, 0.7, sdy, sizeof(sdy))){
        item->startDate.year = atoi(sdy);
    }
    SetPenColor("Black");
    drawTextMiddle(1,1.5,3.5,4.5,"-");
    if(textbox(GenUIID(0), 1.5, 3.65, 0.5, 0.7, sdm, sizeof(sdm))){
        item->startDate.month = atoi(sdm);
    }
    SetPenColor("Black");
    drawTextMiddle(2,2.5,3.5,4.5,"-");
    if(textbox(GenUIID(0), 2.5, 3.65, 0.5, 0.7, sdd, sizeof(sdd))){
        item->startDate.date = atoi(sdd);
    }
    
    //end date
    if(textbox(GenUIID(0), 0.5, 2.65, 0.5, 0.7, edy, sizeof(edy))){
        item->startDate.year = atoi(edy);
    }
    SetPenColor("Black");
    drawTextMiddle(1,1.5,2.5,3.5,"-");
    if(textbox(GenUIID(0), 1.5, 2.65, 0.5, 0.7, edm, sizeof(edm))){
        item->startDate.month = atoi(edm);
    }
    SetPenColor("Black");
    drawTextMiddle(2,2.5,2.5,3.5,"-");
    if(textbox(GenUIID(0), 2.5, 2.65, 0.5, 0.7, edd, 3)){
        item->startDate.date = atoi(edd);
    }

    //price,etc
    static char price[10] = "price";
    if(textbox(GenUIID(0), 0.5, 1.65, 1, 0.7, price, sizeof(price))){
        item->price = atof(price);
    }

    static char score[10] = "score";
    if(textbox(GenUIID(0), 2.5, 1.65, 1, 0.7, score, sizeof(score))){
        item->score = atof(score);
    }

    static char rate[10] = "rate";
    if(textbox(GenUIID(0), 4.5, 1.65, 1, 0.7, rate, sizeof(rate))){
        item->rate = atof(rate);
    }

    //reserved and total numbers
    static char reserved[10] = "reserved";
    if(textbox(GenUIID(0), 0.5, 0.65, 1, 0.7, reserved, sizeof(reserved))){
        item->numberReserved = atoi(reserved);
    }
    SetPenColor("Black");
    drawTextMiddle(1.5,2.5,0.5,1.5,"//");
    static char total[10] = "total";
    if(textbox(GenUIID(0), 2.5, 0.65, 1, 0.7, total, sizeof(total))){
        item->numberTotal = atoi(total);
    }

    //keyword & detail
    strcpy(item->keyword,"keyword");
    strcpy(item->detail,"detail");
    textbox(GenUIID(0), 6.5, 3.5, 5, 2, item->keyword, sizeof(item->keyword));
    textbox(GenUIID(0), 6.5, 1, 5, 2, item->detail, sizeof(item->detail));
    //end of draw input

    //draw apply button
    SetPenColor("Black");
    drawButton(8.5, 0.3, 1, 0.4, "Apply", 0, 0, "White");
    drawButton(10.5, 0.3, 1, 0.4, "Cancel", 0, 0, "White");
}

void drawDetails(int id)
{
    travelItem *ptr;
    //the previous function goThrough() went wrong
    //substituted verion
    ptr = itemHead;
    int i=0;
    while (ptr != NULL && i<itemNum)
    {
    	i++;
        if(ptr->ID == id){
        	break;
		}
        else
			ptr = ptr->nextItem;
    }
    
    drawTextMiddle(8.0,12.0,4.5,5.5,ptr->name);
    char wholeDate[200];
    sprintf(wholeDate,"%d-%d-%d to %d-%d-%d", 
        ptr->startDate.year, ptr->startDate.month, ptr->startDate.date,
        ptr->endDate.year, ptr->endDate.month, ptr->endDate.date);   
    drawTextMiddle(8.0,12.0,4.0,4.5,wholeDate);
    char price[20];
    sprintf(price,"$%d",ptr->price);
    drawTextMiddle(8.0,12.0,3.5,4.0,price);
    char score[50];
    sprintf(score,"%d/5 wondeful",ptr->score);
    drawTextMiddle(8.0,12.0,3.0,3.5,score);
    char number[100];
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
//    MovePen(x,y);
//    string name=label;
//    DrawTextString(name);
	drawLabel(x,y,label);
}
