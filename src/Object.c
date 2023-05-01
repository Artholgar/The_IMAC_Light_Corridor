#include "Object.h"

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

  glColor4f(0., 0., 0., 0.5f);
  glPushMatrix();
  glTranslatef(camera_x, 0., 0.);
  glRotatef(90, 0., 1., 0.);
  glScalef(2., 2., 2.);
  glTranslatef(p.y, -p.x, -5.0);
  drawSquare();

  glEnd();
  glPopMatrix();
}

void manageBoingBall()
{
  float x = 500.;
  float y = 500.;
}

void drawBall()
{
  glColor3f(0.6, 0.6, 0.8);
  glPushMatrix();
  glScalef(0.5, 0.5, 0.5);
  drawSphere();
  glPopMatrix();
}
