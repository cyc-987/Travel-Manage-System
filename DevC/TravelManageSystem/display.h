#include "myHeader.h"

#ifndef _DISPLAY_H_
#define _DISPLAY_H_

//init the whole display by the status
void initDisplay(int status);

//draw the menu bar of the window
//just put the system status in
void drawMyMenuBar(int status);

//draw the basicWindow
//just put the system status in
void drawBasicWindow(int status);

//draw the left window(which is the main window)
void drawMainWindow();

//draw the right window(which is the side window by the status)
//here are the instructions of the status:
// 0:none
// 1:detail of an item(user interface)
// 2:detail of an item(background interface)
// 3:add an item(background interface)
void drawSideWindow(int status);

//draw the searchbar of the window
void drawSearchBar();

//draw a button with label
void drawButton(double startX, double startY, double w, double h, char* label);

//print the text in middle of a square
void drawTextMiddle(double x1, double x2, double y1, double y2, char* label);
#endif