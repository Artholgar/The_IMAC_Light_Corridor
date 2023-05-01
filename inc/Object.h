#ifndef OBJECT
#define OBJECT

#include "3D_tools.h"
#include "corridor.h"

#define MAX_LIFE 5

/* struct type point */
typedef struct point
{
  float x;
  float y;
} Point;

typedef struct ball
{
  float x;
  float y;
  float z;
} Ball;

Point ConvertCoord(int x, int y);

void drawRacket(int x, int y);

Ball initBall();

void drawBall(Ball b);

void Boing();

int manageBoingBall(Ball *b, int x, int y, Level lvl);

#endif
