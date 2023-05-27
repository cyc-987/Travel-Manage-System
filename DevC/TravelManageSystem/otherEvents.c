#include "myHeader.h"

void CharEventProcess(char ch)
{
	uiGetChar(ch); 
    initDisplay(systemStatus);
}


void KeyboardEventProcess(int key, int event)
{
	uiGetKeyboard(key,event); 
    initDisplay(systemStatus);
}