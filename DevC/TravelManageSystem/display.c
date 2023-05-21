#include "myHeader.h"

void initDisplay(int status)
{
    if(status == 0)
    {
        drawMyMenuBar(status);
    }else if(status == 1)
    {

    }
}

void drawMyMenuBar(int status)
{
    SetPenColor("Black");
    MovePen(0,5.7);
    DrawLine(12,0);
    MovePen(0,6);
    DrawLine(12,0);
}