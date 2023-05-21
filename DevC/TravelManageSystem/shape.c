#include "myHeader.h"

void drawSquare(double startX, double startY, double sizeX, double sizeY)
{
    MovePen(startX,startY);
    DrawLine(sizeX,0);
    DrawLine(0,sizeY);
    DrawLine(-sizeX,0);
    DrawLine(0,-sizeY);
}
