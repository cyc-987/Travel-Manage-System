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

    }
}

void drawMainWindow()
{
    drawSearchBar();
    
}

void drawSideWindow(int status)
{
    if(status == 0){
        drawTextMiddle(8,12,0,5.7,"Nothing to display.");
    }
}

void drawSearchBar()
{
    MovePen(0,5.2);
    DrawLine(8,0);

    drawButton(6.1, 5.25, 0.8, 0.4, "Search");
    drawButton(7.1, 5.25, 0.8, 0.4, "Reset");
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

void drawButton(double startX, double startY, double w, double h, char* label)
{
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