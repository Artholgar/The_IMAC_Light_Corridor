#ifndef OBJECT
#define OBJECT

#include "3D_tools.h"

#define MAX_LIFE 5

/* struct type point */
typedef struct point
{
  float x;
  float y;
} Point;

Point ConvertCoord(int x, int y);

void drawRacket(int x, int y);

void drawBall();

#endif
