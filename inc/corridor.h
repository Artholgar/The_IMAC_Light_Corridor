#ifndef CORRIDOR
#define CORRIDOR

#include "3D_tools.h"

typedef struct obstacle
{
    int x;
    int y;
    int height;
    int width;
} *Obstacle;

typedef struct corridorCel
{
    float offset;
    struct obstacle *obs;
    struct corridorCel *next;
} *CorridorCel;

typedef struct level
{
    int size;
    CorridorCel cels;
    struct level *next;
} *Level;

void allocLevel(Level *lvl);

Level genLevel1();

void drawLevel(Level lvl);

void drawCorridorCel(CorridorCel cel);

#endif