#include "3D_tools.h"

/* Camera parameters and functions */
float theta = 0.0f;		 // Angle between x axis and viewpoint
float phy = 90.0f;		 // Angle between z axis and viewpoint
float dist_zoom = 27.0f; // Distance between origin and viewpoint

float camera_x = 0.0;
float camera_y = 0.0;
float camera_z = 0.0;

void setCamera()
{
	/* gluLookAt(dist_zoom * cos(toRad(theta)) * sin(toRad(phy)),
			  dist_zoom * sin(toRad(theta)) * sin(toRad(phy)),
			  dist_zoom * cos(toRad(phy)),
			  0., 0., 0.,
			  0.0, 0.0, 1.0); */
	gluLookAt(camera_x - dist_zoom, camera_y, camera_z, camera_x, camera_y, camera_z, 0.0, 0.0, 1.0);
}

/* Convert degree to radians */
float toRad(float deg)
{
	return deg * M_PI / 180.0f;
}

void drawSquare()
{
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
}

void drawCircle()
{
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0, 0.0, 0.0);
	float step_rad = 2 * M_PI / (float)NB_SEG_CIRCLE;
	for (int i = 0; i <= NB_SEG_CIRCLE; i++)
	{
		glVertex3f(cos(i * step_rad), sin(i * step_rad), 0.0f);
	}
	glEnd();
}

void drawCone()
{
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0, 0.0, 1.0);
	float step_rad = 2 * M_PI / (float)NB_SEG_CIRCLE;
	for (int i = 0; i <= NB_SEG_CIRCLE; i++)
	{
		glVertex3f(cos(i * step_rad), sin(i * step_rad), 0.0f);
	}
	glEnd();
}

void drawSphere()
{
	gluSphere(gluNewQuadric(), 1.0, NB_SEG_CIRCLE, NB_SEG_CIRCLE);
}
