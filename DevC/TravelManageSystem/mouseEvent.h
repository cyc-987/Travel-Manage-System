#include "myHeader.h"

#ifndef _MOUSE_EVENT_H_
#define _MOUSE_EVENT_H_

void myMouseEvent (int x, int y, int button, int event);

int isInRegion(double mouseX, double mouseY, double x, double y, double w, double h);
#endif