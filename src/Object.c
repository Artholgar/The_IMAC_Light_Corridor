#include "Object.h"

double moveBallX = 0.5;
double moveBallY = 0;
double moveBallZ = 0;

/* util function */
Point ConvertCoord(int x, int y)
{
  Point p;
  p.x = (((float)x) / 100.) - 5.;
  p.y = (((float)y) / 100.) - 5.;
  return p;
}

/* drawer */
void drawRacket(int x, int y)
{
  Point p = ConvertCoord(x, y);
  glColor3f(1., 1., 1.);

  glPushMatrix();
  glTranslatef(camera_x, 0., 0.);
  glRotatef(90, 0., 1., 0.);
  glScalef(2., 2., 2.);
  glTranslatef(p.y, -p.x, -5.0);
  glBegin(GL_LINE_LOOP);
  glVertex3f(-0.5, -0.5, 0.0);
  glVertex3f(0.5, -0.5, 0.0);
  glVertex3f(0.5, 0.5, 0.0);
  glVertex3f(-0.5, 0.5, 0.0);
  glEnd();

  glEnd();
  glPopMatrix();
}

Ball initBall()
{
  Ball b;
  b.x = 0.1;
  b.y = 0.;
  b.z = 0.;

  return b;
}

void drawBall(Ball b)
{
  glColor3f(0.6, 0.6, 0.8);
  glPushMatrix();
  glTranslatef(b.x, b.y, b.z);
  glScalef(0.5, 0.5, 0.5);
  drawSphere();
  glPopMatrix();
}

void Boing(int x, int y, int z)
{
  moveBallX *= x;
  moveBallY *= y;
  moveBallZ *= z;
}

int manageBoingBall(Ball *b, int x, int y, Level lvl)
{
  Point cursor = ConvertCoord(x, y);

  if (b->x >= (lvl->size * 20.) - 10.)
  {
    moveBallX *= -1;
  }
  else if (b->x <= camera_x)
  {
    if (b->y <= cursor.y + 0.5 && b->y >= cursor.y - 0.5 && b->z <= cursor.x + 0.5 && b->z >= cursor.x - 0.5)
    {
      moveBallX *= -1;
      moveBallY = cursor.x - b->z;
      moveBallZ = cursor.y - b->y;
    }
    else
    {
      moveBallX = 0.5;
      moveBallY = 0;
      moveBallZ = 0;

      b->x = 0.1;
      b->y = 0.;
      b->z = 0.;

      return 1;
    }
  }
  else
  {
    // Check collision with walls
    for (CorridorCel cel = lvl->cels; cel != NULL; cel = cel->next)
    {
      if (b->x <= cel->offset + 10 && b->x >= cel->offset - 10)
      {
        if (b->y >= 10 || b->y <= -10)
        {
          moveBallY *= -1;
        }

        if (b->z >= 10 || b->z <= -10)
        {
          moveBallZ *= -1;
        }

        if (cel->obs != NULL)
        {
          if (b->x >= cel->offset - 0.5 && b->x <= cel->offset)
          {
            if (b->y >= cel->obs->y - (cel->obs->width / 2) && b->y <= cel->obs->y + (cel->obs->width / 2))
            {
              if (b->z >= cel->obs->x - (cel->obs->height / 2) && b->z <= cel->obs->x + (cel->obs->height / 2))
              {
                moveBallX *= -1;
              }
            }
          }
        }
      }
    }
  }

  b->x += moveBallX;
  b->y += moveBallY;
  b->z += moveBallZ;

  return 0;
}
