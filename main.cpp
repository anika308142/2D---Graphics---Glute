/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

#include<math.h>


static float	tx	=  0.0;
static float	ty	=  0.0;
float rr=0;
float p=-2.3;

//float p=-2.3;
void DrawCircle(float cx, float cy, float rx,float ry, int num_segments)
{
	glBegin(GL_TRIANGLE_FAN);
	for(int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

		float x = rx * cosf(theta);//calculate the x component
		float y = ry * sinf(theta);//calculate the y component

		glVertex2f(x + cx, y + cy);//output vertex

	}
	glEnd();
}
void DrawCircleHalf(float cx, float cy, float rx,float ry, int num_segments)
{
	glBegin(GL_TRIANGLE_FAN);
	for(int ii = 0; ii < num_segments/2; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

		float x = rx * cosf(theta);//calculate the x component
		float y = ry * sinf(theta);//calculate the y component

		glVertex2f(x + cx, y + cy);//output vertex

	}
	glEnd();
}

void display(void)
{if(p<=+1.0)
p=p+0.0002;
else
p=-2.3;
    glutPostRedisplay();

    glClear(GL_COLOR_BUFFER_BIT);


glPushMatrix();
glColor3f(0.5,0.5,0.5);//grey
//glTranslatef(tx,ty,0);
  glBegin(GL_QUADS);
   glVertex2f(2,-0.5);
   glVertex2f(-5,-0.7);
   glVertex2f(-5,-1);
   glVertex2f(2,-1);
  glEnd();
//line
glPushMatrix();
glColor3f(1,1,1);
glTranslatef(tx,ty,0);
glBegin(GL_QUADS);
   glVertex2f(p+0.75,-0.75);
   glVertex2f(p+0.25,-0.75);
   glVertex2f(p+0.25,-0.8);
   glVertex2f(p+0.75,-0.8);
  glEnd();
glPopMatrix();//2
glPushMatrix();
glColor3f(1,1,1);
glTranslatef(tx,ty,0);
glBegin(GL_QUADS);
   glVertex2f(p+0.75-0.9,-0.75);
   glVertex2f(p+0.25-0.9,-0.75);
   glVertex2f(p+0.25-0.9,-0.8);
   glVertex2f(p+0.75-0.9,-0.8);
  glEnd();
glPopMatrix();

//lamp post
glPushMatrix();
glColor3f(0,0,0);
glTranslatef(tx,ty,0);
glBegin(GL_QUADS);
   glVertex2f(p+0.35,-0.6);
   glVertex2f(p+0.30,-0.6);
   glVertex2f(p+0.3,0.6);
   glVertex2f(p+0.35,0.6);
  glEnd();
glPopMatrix();//4
//head of lamppost
glPushMatrix();
glColor3f(255,255,0);
glTranslatef(tx,ty,0);
glBegin(GL_QUADS);
   glVertex2f(p+0.3,0.6);
   glVertex2f(p+0.25,0.6);
   glVertex2f(p+0.25,0.45);
   glVertex2f(p+0.3,0.45);
  glEnd();
glPopMatrix();//5
//glColor3f(0,0,0);
//glTranslatef(tx,ty,0);
//moon
/*glBegin(GL_POLYGON);

   glVertex2f(p+0.77,0.8);
   glVertex2f(p+0.60,0.8);
   glVertex2f(p+0.60,0.7);
   glVertex2f(p+0.77,0.7);
  glEnd();*/

//road

//glPopMatrix();//6
/*for(int i=0;i<360;i+=30){
glColor3ub(255,150,0);
glPushMatrix();
glRotated(i,0,0,1);
DrawCircle(0,0,80,80,500);
glPopMatrix();
}
glEnd();*/

//cart
glPushMatrix();
glColor3f(0.5,1,0);
//glTranslatef(tx,ty,0);
glBegin(GL_QUADS);
   glVertex2f(0.2,-0.38);
   glVertex2f(-0.2,-0.4);
   glVertex2f(-0.5,-0.07);
   glVertex2f(0.5,0.0);
  glEnd();
glPopMatrix();//3
//body
glPushMatrix();
glColor3f(0.7,0.5,0.5);
//glTranslatef(tx,ty,0);
glBegin(GL_QUADS);
   glVertex2f(0.2,0.1);
   glVertex2f(0.1,-0.03);
   glVertex2f(0.4,-0.01);
   glVertex2f(0.35,0.1);
  glEnd();
glPopMatrix();//3
glPushMatrix();
glColor3f(0.7,0.5,0.5);
//glTranslatef(tx,ty,0);
glBegin(GL_QUADS);
   glVertex2f(0.1,0.25);
   glVertex2f(0.2,-0.03);
   glVertex2f(0.35,-0.01);
   glVertex2f(0.4,0.25);
  glEnd();
glPopMatrix();//3
//hand
glPushMatrix();
glColor3f(0.7,0.5,0.5);
//glTranslatef(tx,ty,0);
glBegin(GL_QUADS);
   glVertex2f(0.1,0.25);
   glVertex2f(0.15,0.55);
   glVertex2f(0.22,0.55);
   glVertex2f(0.17,0.25);
  glEnd();
glPopMatrix();
glPushMatrix();
glColor3f(0.7,0.5,0.5);
//glTranslatef(tx,ty,0);
glBegin(GL_QUADS);
   glVertex2f(0.34,0.25);
   glVertex2f(0.37,0.55);
   glVertex2f(0.44,0.55);
   glVertex2f(0.4,0.25);
  glEnd();
glPopMatrix();

//head
glPushMatrix();
glColor3f(255,240,17);
//glTranslatef(tx,ty,0);
glBegin(GL_POLYGON);
   glVertex2f(0.21,0.28);
      glVertex2f(0.23,0.25);

   glVertex2f(0.33,0.28);
   glVertex2f(0.34,0.4);
   glVertex2f(0.21,0.4);
  glEnd();
glPopMatrix();
//leg
glPushMatrix();
glColor3f(0,0,0);
//glTranslatef(tx,ty,0);
glBegin(GL_POLYGON);
   glVertex2f(-0.4,-0.07);
   glVertex2f(-0.8,0.1);
   glVertex2f(-0.8,0.2);
   glVertex2f(-0.3,-0.05);
  glEnd();
glPopMatrix();//3
//face
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.21f, 0.35f);
glVertex2f(0.23f, 0.36f);
glEnd();
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.23f, 0.36f);
glVertex2f(0.25f, 0.35f);
glEnd();
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.28f, 0.35f);
glVertex2f(0.30f, 0.36f);
glEnd();
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.30f, 0.36f);
glVertex2f(0.32f, 0.35f);
glEnd();
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(0.26f, 0.3f);
glVertex2f(0.29f, 0.3f);
glEnd();
//shoe
glPushMatrix();
glColor3f(1,0,0);
//glTranslatef(tx,ty,0);
glBegin(GL_POLYGON);
   glVertex2f(-0.8,0.1);
   glVertex2f(-0.9,0.3);
   glVertex2f(-0.9,0.15);
   glVertex2f(-0.8,0.2);
  glEnd();
glPopMatrix();//3


///wheel
if(rr<360)
    rr+=.02;
else rr=0;

glPushMatrix();
glTranslated(-.21,-0.5,0);
glRotated(rr,0,0,1);
glColor3f(1,0,0);
DrawCircle(0,0,.17,.17,500);
glColor3f(1,1,1);
DrawCircle(0,0,.17,.015,500);
DrawCircle(0,0,.015,.17,500);
glPopMatrix();

glPushMatrix();
glTranslated(.19,-0.5,0);
glRotated(rr,0,0,1);
glColor3f(1,0,0);
DrawCircle(0,0,.17,.17,500);
glColor3f(1,1,1);
DrawCircle(0,0,.17,.015,500);
DrawCircle(0,0,.015,.17,500);
glPopMatrix();

///cap
glPushMatrix();
glTranslated(.26,-0.03,0);
glScaled(.85,.85,1);
glColor3f(1,0,0);
DrawCircleHalf(0,.5,.1,.09,500);
DrawCircle(-.11,.51,.055,.01,500);
glPopMatrix();

	glFlush();
}

void init(void)
{
	glClearColor (0.0, 0.0, 1.0, 1.0);
	//glOrtho(-500.0, 500.0, -500.0, 500.0, -1.0, 1.0);

}

int main()
{
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (600, 600);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("moving_object");
	init();
    glutDisplayFunc(display);
	//glutKeyboardFunc(my_keyboard);
	//glutSpecialFunc(spe_key);
	//glutMouseFunc(my_mouse);
	glutMainLoop();
	return 0;
}



