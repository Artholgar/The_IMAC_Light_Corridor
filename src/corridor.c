#include "corridor.h"

void AllocObstacle(Obstacle *obs, int x, int y, int height, int width)
{
    *obs = (Obstacle)malloc(sizeof(Obstacle *));

    (*obs)->x = x;
    (*obs)->y = y;
    (*obs)->height = height;
    (*obs)->width = width;
}

void allocCorridorCel(CorridorCel *cel, int offset)
{
    *cel = (CorridorCel)malloc(sizeof(CorridorCel *));

    (*cel)->offset = offset;

    (*cel)->obs = NULL;
}

void allocLevel(Level *lvl)
{
    *lvl = (Level)malloc(sizeof(Level *));

    (*lvl)->size = 0;
    (*lvl)->cels = NULL;
    (*lvl)->next = NULL;
}

Level genLevel1()
{
    Level lvl;

    allocLevel(&lvl);

    lvl->size = 10;

    for (int i = 1; i <= lvl->size; i++)
    {
        CorridorCel cels = lvl->cels;

        allocCorridorCel(&(lvl->cels), (lvl->size - i) * 20.);

        lvl->cels->next = cels;
    }

    CorridorCel current = lvl->cels;

    current = current->next;

    AllocObstacle(&(current->obs), 0, -5, 20, 10);

    current = current->next;
    current = current->next;
    current = current->next;
    current = current->next;
    current = current->next;
    current = current->next;
    current = current->next;

    AllocObstacle(&(current->obs), -5, -5, 10, 10);

    return lvl;
}

void drawLevel(Level lvl)
{
    for (CorridorCel cel = lvl->cels; cel != NULL; cel = cel->next)
    {
        drawCorridorCel(cel);
    }
}

void drawCorridorCel(CorridorCel cel)
{
    glColor3f(0., 0., 0.9);
    glPushMatrix();
    glTranslatef(cel->offset, 0., 10.);
    glScalef(20., 20., 20.);
    drawSquare();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cel->offset, 0., -10.);
    glScalef(20., 20., 20.);
    drawSquare();
    glPopMatrix();

    glColor3f(0., 0., 0.4);
    glPushMatrix();
    glRotatef(90, 1., 0., 0.);
    glTranslatef(cel->offset, 0., 10.);
    glScalef(20., 20., 20.);
    drawSquare();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90, 1., 0., 0.);
    glTranslatef(cel->offset, 0., -10.);
    glScalef(20., 20., 20.);
    drawSquare();
    glPopMatrix();

    if (cel->obs != NULL)
    {
        glColor3f(0., 0., 0.2);
        glPushMatrix();
        glTranslatef(cel->offset, 0., 0.);
        glRotatef(90, 0., 1., 0.);
        glTranslatef(cel->obs->x, cel->obs->y, 0.);
        glScalef(cel->obs->height, cel->obs->width, 1.);
        drawSquare();
        glPopMatrix();
    }
}