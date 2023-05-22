#include "myHeader.h"

bool isLog = TRUE;
int systemStatus = 0;
int itemNum = 0;
travelItem *itemHead = NULL;
fileHead *FileHead = NULL;
int page = 1;


void Main()
{
	SetWindowTitle("���ι���ϵͳ");
	SetWindowSize(12,6);
	InitGraphics();
	InitGUI();
	
	registerMouseEvent(myMouseEvent);
	Log("initial complete");

	initDisplay(systemStatus);
}
