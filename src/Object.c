#include "Object.h"

double moveBallX = 0;
double moveBallY = 0;
double moveBallZ = 0.5;

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
  b.x = 0.;
  b.y = 0.;
  b.z = 0.;

  return b;
}

void drawBall(Ball b)
{
  glColor3f(0.6, 0.6, 0.8);
  glPushMatrix();
  glTranslatef(camera_x + 4.95 + b.z, b.y - 0.5, b.x);
  glScalef(0.5, 0.5, 0.5);
  drawSphere();
  glPopMatrix();
}

void Boing()
{
  moveBallX *= -1;
  moveBallY *= -1;
  moveBallZ *= -1;
}

int manageBoingBall(Ball *b, int x, int y)
{
  Point cursor = ConvertCoord(x, y);

  if (b->z >= 20)
  {
    Boing();
  }
  else if (b->z + moveBallZ <= -12)
  {
    if (b->x + moveBallX >= cursor.x - 0.9 && b->x + moveBallX <= cursor.x + 0.9)
    {
      if (b->y + moveBallY >= cursor.y - 0.9 && b->y + moveBallX <= cursor.y + 0.9)
      {
        moveBallZ *= 1.2;
        Boing();
      }
    }
    else
    {
      moveBallX = 0;
      moveBallY = 0;
      moveBallZ = 0.5;

      b->z = 0.;

      return 1;
    }
  }

  b->x += moveBallX;
  b->y += moveBallY;
  b->z += moveBallZ;

  return 0;
}
