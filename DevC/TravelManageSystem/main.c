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
	SetWindowTitle("���ι���ϵͳ");
	SetWindowSize(10,6);
	InitGraphics();
	
	Log("initial complete");

	display();
}