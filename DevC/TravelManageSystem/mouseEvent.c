#include "myHeader.h"

void myMouseEvent (int x, int y, int button, int event)
{
    double mouseX, mouseY;
    mouseX = ScaleXInches(x);
	mouseY = ScaleYInches(y);

    //mouse on button

    //search button
    if(isInRegion(mouseX,mouseY,6.1, 5.25, 0.8, 0.4)){
        drawButton(6.1, 5.25, 0.8, 0.4, "Search",1,1,"Gray");
    }else{
        drawButton(6.1, 5.25, 0.8, 0.4, "Search",1,0,"White");
    }
    //reset button
    if(isInRegion(mouseX,mouseY,7.1, 5.25, 0.8, 0.4)){
        drawButton(7.1, 5.25, 0.8, 0.4, "Search",1,1,"Gray");
    }else{
        drawButton(7.1, 5.25, 0.8, 0.4, "Search",1,0,"White");
    }
    //end of mouse on button
}

int isInRegion(double mouseX, double mouseY, double x, double y, double w, double h)
{
    if(mouseX < x+w 
    && mouseX > x
    && mouseY < y+h
    && mouseY > y){
        return 1;
    }else return 0;
}