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
            refresh();
        }else if(isInRegion(mouseX,mouseY,0, 5.7, 0.75, 0.3)){
            drawButton(0, 5.7, 0.75, 0.3, "Refresh",1,1,"Light Gray");
        }else{
            drawButton(0, 5.7, 0.75, 0.3, "Refresh",1,1,"White");
        }
        //save
        if(isInRegion(mouseX,mouseY,0.75, 5.7, 0.75, 0.3) && (event == BUTTON_DOWN) && (button == LEFT_BUTTON)){
            drawButton(0.75, 5.7, 0.75, 0.3, "Save",1,1,"LightBlue");
            Log("push save");
            saveFile();
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
                sidebarStatus = 2;
                DisplayClear();
                initDisplay(systemStatus);
            }else if(systemStatus == 1){
                systemStatus = 0;
                sidebarStatus = 1;
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
        if(isInRegion(mouseX,mouseY,7.7, 1.2, 1, 0.4) && (event == BUTTON_DOWN) && (button == LEFT_BUTTON)){
            drawButton(7.7, 1.2, 1, 0.4, "Apply",1,1,"LightBlue");
            Log("push apply");
            addItem(currentItem);
            //Log("apply return success");
            sidebarStatus = 0;
            systemStatus = 1;
            refresh();
            //Log("init display success");
        }else if(isInRegion(mouseX,mouseY,7.7, 1.2, 1, 0.4)){
            drawButton(7.7, 1.2, 1, 0.4, "Apply",1,1,"Light Gray");
        }else{
            drawButton(7.7, 1.2, 1, 0.4, "Apply",1,1,"White");
        }

        //cancel
        if(isInRegion(mouseX,mouseY,9.7, 1.2, 1, 0.4) && (event == BUTTON_DOWN) && (button == LEFT_BUTTON)){
            drawButton(9.7, 1.2, 1, 0.4, "Cancel",1,1,"LightBlue");
            Log("push cancel");
            free(currentItem);
            currentItem = NULL;
            sidebarStatus = 0;
            systemStatus = 1;
            initDisplay(systemStatus);
        }else if(isInRegion(mouseX,mouseY,9.7, 1.2, 1, 0.4)){
            drawButton(9.7, 1.2, 1, 0.4, "Cancel",1,1,"Light Gray");
        }else{
            drawButton(9.7, 1.2, 1, 0.4, "Cancel",1,1,"White");
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

    //agency,delete
    //delete button
    if(systemStatus == 1 && sidebarStatus == 2){
        if(isInRegion(mouseX,mouseY,9.1, 0.3, 1.8, 0.4) && (event == BUTTON_DOWN) && (button == LEFT_BUTTON)){
            drawButton(9.1, 0.3, 1.8, 0.4, "Delete",1,1,"LightBlue");
            Log("push delete");
            clearSideWindow();
            deleteItem(currentItem);
            refresh();
        }else if(isInRegion(mouseX,mouseY,9.1, 0.3, 1.8, 0.4)){
            drawButton(9.1, 0.3, 1.8, 0.4, "Delete",1,1,"Light Gray");
        }else{
            drawButton(9.1, 0.3, 1.8, 0.4, "Delete",1,1,"White");
        }
    }
    //end of delete button

    //user,reserve button
    if(systemStatus == 0 && sidebarStatus == 1){
        if(currentItem->isReserved){
            if(isInRegion(mouseX,mouseY,9.1, 0.3, 1.8, 0.4) && (event == BUTTON_DOWN) && (button == LEFT_BUTTON)){
                drawButton(9.1, 0.3, 1.8, 0.4, "Unreserve",1,1,"LightBlue");
                Log("push unreserve");
                clearSideWindow();
                currentItem->numberReserved --;
                currentItem->isReserved = FALSE;
                initDisplay(systemStatus);
            }else if(isInRegion(mouseX,mouseY,9.1, 0.3, 1.8, 0.4)){
                drawButton(9.1, 0.3, 1.8, 0.4, "Unreserve",1,1,"Light Gray");
            }else{
                drawButton(9.1, 0.3, 1.8, 0.4, "Unreserve",1,1,"White");
            }
        }else{
            if(isInRegion(mouseX,mouseY,9.1, 0.3, 1.8, 0.4) && (event == BUTTON_DOWN) && (button == LEFT_BUTTON)){
                drawButton(9.1, 0.3, 1.8, 0.4, "Reserve",1,1,"LightBlue");
                Log("push reserve");
                clearSideWindow();
                currentItem->numberReserved ++;
                currentItem->isReserved = TRUE;
                initDisplay(systemStatus);
            }else if(isInRegion(mouseX,mouseY,9.1, 0.3, 1.8, 0.4)){
                drawButton(9.1, 0.3, 1.8, 0.4, "Reserve",1,1,"Light Gray");
            }else{
                drawButton(9.1, 0.3, 1.8, 0.4, "Reserve",1,1,"White");
            }
        }
    }
    //end of reserve buttons
    //end of sidebar event

    //main window event
    //next page
    if(systemStatus == 0 | systemStatus == 1){
        if(isInRegion(mouseX,mouseY,6.5,0.2,1,0.6) && (event == BUTTON_DOWN) && (button == LEFT_BUTTON)){
            drawButton(6.5,0.2,1,0.6,"Next Page",1,1,"LightBlue");
            Log("push next page");
            if(page < MaxPage){
                page++;
            }
            initDisplay(systemStatus);
        }else if(isInRegion(mouseX,mouseY,6.5,0.2,1,0.6)){
            drawButton(6.5,0.2,1,0.6,"Next Page",1,1,"Light Gray");
        }else{
            drawButton(6.5,0.2,1,0.6,"Next Page",1,1,"White");
        }
    }
    //pre page
    if(systemStatus == 0 | systemStatus == 1){
        if(isInRegion(mouseX,mouseY,5,0.2,1,0.6) && (event == BUTTON_DOWN) && (button == LEFT_BUTTON)){
            drawButton(5,0.2,1,0.6,"Pre Page",1,1,"LightBlue");
            Log("push pre page");
            if(page > 1){
                page--;
            }
            initDisplay(systemStatus);
        }else if(isInRegion(mouseX,mouseY,5,0.2,1,0.6)){
            drawButton(5,0.2,1,0.6,"Pre Page",1,1,"Light Gray");
        }else{
            drawButton(5,0.2,1,0.6,"Pre Page",1,1,"White");
        }
    }
    //five more info buttons
    if(systemStatus == 0 | systemStatus == 1)
    {
        //button0
        if(lineIsActive[0] == 1){
            if(isInRegion(mouseX,mouseY,6.6,4.4,0.8,0.4) && (event == BUTTON_DOWN) && (button == LEFT_BUTTON)){
                drawButton(6.6,4.4,0.8,0.4,"more info.",1,1,"LightBlue");
                Log("push more info");
                if(systemStatus == 0){
                    sidebarStatus = 1;
                }else{
                    sidebarStatus = 2;
                }
                locateToCurrentItem(page, 0);   
                initDisplay(systemStatus);
            }else if(isInRegion(mouseX,mouseY,6.6,4.4,0.8,0.4)){
                drawButton(6.6,4.4,0.8,0.4,"more info.",1,1,"Light Gray");
            }else{
                drawButton(6.6,4.4,0.8,0.4,"more info.",1,1,"White");
            }
        }
        //button1
        if(lineIsActive[1] == 1){
            if(isInRegion(mouseX,mouseY,6.6,3.6,0.8,0.4) && (event == BUTTON_DOWN) && (button == LEFT_BUTTON)){
                drawButton(6.6,3.6,0.8,0.4,"more info.",1,1,"LightBlue");
                Log("push more info");
                if(systemStatus == 0){
                    sidebarStatus = 1;
                }else{
                    sidebarStatus = 2;
                }
                locateToCurrentItem(page, 1);   
                initDisplay(systemStatus);
            }else if(isInRegion(mouseX,mouseY,6.6,3.6,0.8,0.4)){
                drawButton(6.6,3.6,0.8,0.4,"more info.",1,1,"Light Gray");
            }else{
                drawButton(6.6,3.6,0.8,0.4,"more info.",1,1,"White");
            }
        }
        //button2
        if(lineIsActive[2] == 1){
            if(isInRegion(mouseX,mouseY,6.6,2.8,0.8,0.4) && (event == BUTTON_DOWN) && (button == LEFT_BUTTON)){
                drawButton(6.6,2.8,0.8,0.4,"more info.",1,1,"LightBlue");
                Log("push more info");
                if(systemStatus == 0){
                    sidebarStatus = 1;
                }else{
                    sidebarStatus = 2;
                }
                locateToCurrentItem(page, 2);   
                initDisplay(systemStatus);
            }else if(isInRegion(mouseX,mouseY,6.6,2.8,0.8,0.4)){
                drawButton(6.6,2.8,0.8,0.4,"more info.",1,1,"Light Gray");
            }else{
                drawButton(6.6,2.8,0.8,0.4,"more info.",1,1,"White");
            }
        }
        //button3
        if(lineIsActive[3] == 1){
            if(isInRegion(mouseX,mouseY,6.6,2,0.8,0.4) && (event == BUTTON_DOWN) && (button == LEFT_BUTTON)){
                drawButton(6.6,2,0.8,0.4,"more info.",1,1,"LightBlue");
                Log("push more info");
                if(systemStatus == 0){
                    sidebarStatus = 1;
                }else{
                    sidebarStatus = 2;
                }
                locateToCurrentItem(page, 3);   
                initDisplay(systemStatus);
            }else if(isInRegion(mouseX,mouseY,6.6,2,0.8,0.4)){
                drawButton(6.6,2,0.8,0.4,"more info.",1,1,"Light Gray");
            }else{
                drawButton(6.6,2,0.8,0.4,"more info.",1,1,"White");
            }
        }
        //button4
        if(lineIsActive[4] == 1){
            if(isInRegion(mouseX,mouseY,6.6,1.2,0.8,0.4) && (event == BUTTON_DOWN) && (button == LEFT_BUTTON)){
                drawButton(6.6,1.2,0.8,0.4,"more info.",1,1,"LightBlue");
                Log("push more info");
                if(systemStatus == 0){
                    sidebarStatus = 1;
                }else{
                    sidebarStatus = 2;
                }
                locateToCurrentItem(page, 4);   
                initDisplay(systemStatus);
            }else if(isInRegion(mouseX,mouseY,6.6,1.2,0.8,0.4)){
                drawButton(6.6,1.2,0.8,0.4,"more info.",1,1,"Light Gray");
            }else{
                drawButton(6.6,1.2,0.8,0.4,"more info.",1,1,"White");
            }
        }
    }
    //end of five more info buttons
    //end of main window event
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

void locateToCurrentItem(int page, int offset)
{
    int count = 1;
    travelItem* head = currentHead;
    //move the head to the current page
    while(count<page){
        int i;
        for(i=1;i<=5;i++){
            head = head->nextItem;
        }
        count++;
    }

    int k;
    for(k=1;k<=offset;k++){
        head = head->nextItem;
    }

    currentItem = head;
}