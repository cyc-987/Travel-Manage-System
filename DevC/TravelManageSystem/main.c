#include "myHeader.h"

bool isLog = TRUE;
int systemStatus = 0;
int sidebarStatus = 0;
int itemNum = 0;
travelItem *itemHead = NULL;
travelItem *currentItem = NULL;
travelItem *currentHead = NULL;
fileHead *FileHead = NULL;
int page = 1;
char searchText[100] = "";
bool MaxPage = 1;

void Main()
{
	SetWindowTitle("Travel Manage System");
	SetWindowSize(12,6);
	InitGraphics();
	InitGUI();

	//init
	DefineColor("LightBlue",0.01176, 0.60784, 0.89804);
	openFile();
	
	registerMouseEvent(myMouseEvent);
	registerCharEvent(CharEventProcess);        
	registerKeyboardEvent(KeyboardEventProcess); 
	Log("initial complete");
	
	refresh();
}
