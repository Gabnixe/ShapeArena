#include "debug.h"

#include <stdio.h>
#include "raylib.h"

void drawDebug()
{
    drawFPS();
}

void drawFPS()
{
    char buffer[100];
    sprintf(buffer, "%.0f FPS", 1 / GetFrameTime());
    DrawText(buffer, 0, 0, 20, BLACK);
}