#include "myHeader.h"

void myMouseEvent (int x, int y, int button, int event)
{
    double mouseX, mouseY;
    mouseX = ScaleXInches(x);
	mouseY = ScaleYInches(y);
    uiGetMouse(x,y,button,event);
    initDisplay(systemStatus);
	
    //mouse on button

    //search button
    if(systemStatus != 2){
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
    }
    //end of mouse on button

    //menu bar button event

    if(systemStatus != 2){
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
    }

    if(systemStatus != 2){
        //output button
        if(isInRegion(mouseX,mouseY,9, 5.7, 0.75, 0.3) && (event == BUTTON_DOWN) && (button == LEFT_BUTTON)){
            drawButton(9, 5.7, 0.75, 0.3, "Output",1,1,"LightBlue");
            Log("push output");
            outputFile(currentHead);
        }else if(isInRegion(mouseX,mouseY,9, 5.7, 0.75, 0.3)){
            drawButton(9, 5.7, 0.75, 0.3, "Output",1,1,"Light Gray");
        }else{
            drawButton(9, 5.7, 0.75, 0.3, "Output",1,0,"White");
        }
        //end of menubar mouse event
    }

    //side bar event
    //agency,apply
    if(systemStatus == 2 && sidebarStatus == 3){
        //apply
        if(isInRegion(mouseX,mouseY,8.5, 0.3, 1, 0.4) && (event == BUTTON_DOWN) && (button == LEFT_BUTTON)){
            drawButton(8.5, 0.3, 1, 0.4, "Apply",1,1,"LightBlue");
            Log("push apply");
            addItem(currentItem);
            //Log("apply return success");
            sidebarStatus = 0;
            systemStatus = 1;
            initDisplay(systemStatus);
            //Log("init display success");
        }else if(isInRegion(mouseX,mouseY,8.5, 0.3, 1, 0.4)){
            drawButton(8.5, 0.3, 1, 0.4, "Apply",1,1,"Light Gray");
        }else{
            drawButton(8.5, 0.3, 1, 0.4, "Apply",1,1,"White");
        }

        //cancel
        if(isInRegion(mouseX,mouseY,10.5, 0.3, 1, 0.4) && (event == BUTTON_DOWN) && (button == LEFT_BUTTON)){
            drawButton(10.5, 0.3, 1, 0.4, "Cancel",1,1,"LightBlue");
            Log("push cancel");
            free(currentItem);
            currentItem = NULL;
            sidebarStatus = 0;
            systemStatus = 1;
            initDisplay(systemStatus);
        }else if(isInRegion(mouseX,mouseY,10.5, 0.3, 1, 0.4)){
            drawButton(10.5, 0.3, 1, 0.4, "Cancel",1,1,"Light Gray");
        }else{
            drawButton(10.5, 0.3, 1, 0.4, "Cancel",1,1,"White");
        }
    }
    //end of apply event

    //agency,add button
    if(systemStatus == 1 && sidebarStatus != 3){
        if(isInRegion(mouseX,mouseY,2.25, 5.7, 0.75, 0.3) && (event == BUTTON_DOWN) && (button == LEFT_BUTTON)){
            drawButton(2.25, 5.7, 0.75, 0.3, "Add",1,1,"LightBlue");
            clearSideWindow();
            //init
            currentItem = createEmptyItem();
            sidebarStatus = 3;
            systemStatus = 2;
            initDisplay(systemStatus);
            Log("push add");
        }else if(isInRegion(mouseX,mouseY,2.25, 5.7, 0.75, 0.3)){
            drawButton(2.25, 5.7, 0.75, 0.3, "Add",1,1,"Light Gray");
        }else{
            drawButton(2.25, 5.7, 0.75, 0.3, "Add",1,1,"White");
        }
    }
    //end of add button

    //user,reserve button
    if(systemStatus == 0 && sidebarStatus == 1){
        if(isInRegion(mouseX,mouseY,9.1, 0.3, 1.8, 0.4) && (event == BUTTON_DOWN) && (button == LEFT_BUTTON)){
            drawButton(9.1, 0.3, 1.8, 0.4, "Reserve",1,1,"LightBlue");
            Log("push reserve");
            clearSideWindow();
            currentItem->numberReserved ++;
            initDisplay(systemStatus);
        }else if(isInRegion(mouseX,mouseY,9.1, 0.3, 1.8, 0.4)){
            drawButton(9.1, 0.3, 1.8, 0.4, "Reserve",1,1,"Light Gray");
        }else{
            drawButton(9.1, 0.3, 1.8, 0.4, "Reserve",1,1,"White");
        }
    }
    //end of reserve buttons
    //end of sidebar event
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
