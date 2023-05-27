#include "myHeader.h"

bool isLog = TRUE;
int systemStatus = 0;
int itemNum = 0;
travelItem *itemHead = NULL;
fileHead *FileHead = NULL;
int page = 1;


void Main()
{
	SetWindowTitle("Travel Manage System");
	SetWindowSize(12,6);
	InitGraphics();
	InitGUI();

	DefineColor("LightBlue",0.01176, 0.60784, 0.89804);
	
	registerMouseEvent(myMouseEvent);
	Log("initial complete");

	initDisplay(systemStatus);
}
