#include "myHeader.h"

bool isLog = TRUE;
int systemStatus = 0;
int itemNum = 0;
travelItem *itemHead = NULL;
fileHead *FileHead = NULL;

void display()
{
}

void Main()
{
	SetWindowTitle("旅游管理系统");
	SetWindowSize(10,6);
	InitGraphics();
	
	Log("initial complete");

	display();
}