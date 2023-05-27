#include "myHeader.h"

void myMouseEvent (int x, int y, int button, int event)
{
    double mouseX, mouseY;
    mouseX = ScaleXInches(x);
	mouseY = ScaleYInches(y);

    //mouse on button

    //search button
    if(isInRegion(mouseX,mouseY,6.1, 5.25, 0.8, 0.4) && (event == BUTTON_DOWN) && (button == LEFT_BUTTON)){
        drawButton(6.1, 5.25, 0.8, 0.4, "Search",1,1,"LightBlue");
        Log("push search");
    }else if(isInRegion(mouseX,mouseY,6.1, 5.25, 0.8, 0.4)){
        drawButton(6.1, 5.25, 0.8, 0.4, "Search",1,1,"Light Gray");
    }else{
        drawButton(6.1, 5.25, 0.8, 0.4, "Search",1,1,"White");
    }
    //reset button
    if(isInRegion(mouseX,mouseY,7.1, 5.25, 0.8, 0.4) && (event == BUTTON_DOWN) && (button == LEFT_BUTTON)){
        drawButton(7.1, 5.25, 0.8, 0.4, "Reset",1,1,"LightBlue");
        Log("push reset");
    }else if(isInRegion(mouseX,mouseY,7.1, 5.25, 0.8, 0.4)){
        drawButton(7.1, 5.25, 0.8, 0.4, "Reset",1,1,"Light Gray");
    }else{
        drawButton(7.1, 5.25, 0.8, 0.4, "Reset",1,0,"White");
    }
    //end of mouse on button

    //menu bar button event

    //refresh button
    if(isInRegion(mouseX,mouseY,0, 5.7, 0.75, 0.3) && (event == BUTTON_DOWN) && (button == LEFT_BUTTON)){
        drawButton(0, 5.7, 0.75, 0.3, "Refresh",1,1,"LightBlue");
        Log("push refresh");
    }else if(isInRegion(mouseX,mouseY,0, 5.7, 0.75, 0.3)){
        drawButton(0, 5.7, 0.75, 0.3, "Refresh",1,1,"Light Gray");
    }else{
        drawButton(0, 5.7, 0.75, 0.3, "Refresh",1,1,"White");
    }
    //save
    if(isInRegion(mouseX,mouseY,0.75, 5.7, 0.75, 0.3) && (event == BUTTON_DOWN) && (button == LEFT_BUTTON)){
        drawButton(0.75, 5.7, 0.75, 0.3, "Save",1,1,"LightBlue");
        Log("push save");
    }else if(isInRegion(mouseX,mouseY,0.75, 5.7, 0.75, 0.3)){
        drawButton(0.75, 5.7, 0.75, 0.3, "Save",1,1,"Light Gray");
    }else{
        drawButton(0.75, 5.7, 0.75, 0.3, "Save",1,1,"White");
    }
    //change
    if(isInRegion(mouseX,mouseY,1.5, 5.7, 0.75, 0.3) && (event == BUTTON_DOWN) && (button == LEFT_BUTTON)){
        drawButton(1.5, 5.7, 0.75, 0.3, "Change",1,1,"LightBlue");
        Log("push change");
        if(systemStatus == 0){
            systemStatus = 1;
            DisplayClear();
            initDisplay(systemStatus);
        }else if(systemStatus == 1){
            systemStatus = 0;
            DisplayClear();
            initDisplay(systemStatus);
        }
    }else if(isInRegion(mouseX,mouseY,1.5, 5.7, 0.75, 0.3)){
        drawButton(1.5, 5.7, 0.75, 0.3, "Change",1,1,"Light Gray");
    }else{
        drawButton(1.5, 5.7, 0.75, 0.3, "Change",1,1,"White");
    }
    //end of menubar mouse event
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