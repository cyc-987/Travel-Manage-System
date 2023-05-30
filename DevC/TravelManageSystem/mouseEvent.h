#include "myHeader.h"

#ifndef _MOUSE_EVENT_H_
#define _MOUSE_EVENT_H_

void myMouseEvent (int x, int y, int button, int event);

//judge whether the mouse is in the specific region
//return 1 if the result is true
int isInRegion(double mouseX, double mouseY, double x, double y, double w, double h);

//a midterm func used by "more info" buttons
//locate the currentItem point to the selected item
void locateToCurrentItem(int page, int offset);

#endif