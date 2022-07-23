#include<iostream>
#include<math.h>
#include<stdio.h>
#include<Windows.h>
#include<glut.h>
using namespace std;

char name[35] = "Remote Sensing System";
char college[100] = "R N S Institute Of Technology";
char dept[100] = "Department of Computer Science & Engineering";
char heading[100] = " ";
char row1[100] = "Sripradha (1RN19CS155) ";
char row2[100] = "Tejaswini B M (1RN19CS167) ";
char emsg[100] = "Right Click to Start";
char title[50] = "Stages of Remote Sensing";


void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-600, 600, -300, 500, -300, 300);
	glMatrixMode(GL_MODELVIEW);
}

void Drawarc(float sa, float ea, float cx, float cy, float rd)
{
	float PI = 3.14;
	float step = 1.0;
	float angle, x = 0, y = 0, centerX = cx, centerY = cy, radius = rd;

	glBegin(GL_POLYGON);
	for (angle = sa; angle < ea; angle += step)
	{
		float rad;
		rad = PI * angle / 180;
		x = centerX + radius * cos(rad);
		y = centerY + radius * sin(rad);
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}

void aeroplane()
{
	glColor3f(0.46, 0.53, 0.6);
	glBegin(GL_POLYGON);//rectangular body
	glVertex2f(0.0, 30.0);
	glVertex2f(0.0, 55.0);
	glVertex2f(135.0, 55.0);
	glVertex2f(135.0, 30.0);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);//upper triangle construction plane
	glVertex2f(135.0, 55.0);
	glVertex2f(150.0, 50.0);
	glVertex2f(155.0, 45.0);
	glVertex2f(160.0, 40.0);
	glVertex2f(135.0, 40.0);
	glEnd();

	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_LINE_LOOP);//outline of upper triangle plane
	glVertex2f(135.0, 55.0);
	glVertex2f(150.0, 50.0);
	glVertex2f(155.0, 45.0);
	glVertex2f(160.0, 40.0);
	glVertex2f(135.0, 40.0);
	glEnd();

	glColor3f(0.46, 0.53, 0.6);
	glBegin(GL_POLYGON);//lower triangle
	glVertex2f(135.0, 40.0);
	glVertex2f(160.0, 40.0);
	glVertex2f(160.0, 37.0);
	glVertex2f(145.0, 30.0);
	glVertex2f(135.0, 30.0);
	glEnd();

	glColor3f(0.29, 0.0, 0.5);
	glBegin(GL_POLYGON);//back wing
	glVertex2f(0.0, 55.0);
	glVertex2f(0.0, 80.0);
	glVertex2f(10.0, 80.0);
	glVertex2f(40.0, 55.0);
	glEnd();

	glColor3f(0.29, 0.0, 0.5);
	glBegin(GL_POLYGON);//left side wing
	glVertex2f(65.0, 55.0);
	glVertex2f(50.0, 70.0);
	glVertex2f(75.0, 70.0);
	glVertex2f(90.0, 55.0);
	glEnd();

	glColor3f(0.29, 0.0, 0.5);
	glBegin(GL_POLYGON);//rightside wing
	glVertex2f(70.0, 40.0);
	glVertex2f(100.0, 40.0);
	glVertex2f(80.0, 15.0);
	glVertex2f(50.0, 15.0);
	glEnd();
	glFlush();
}
void smoke(int m, int n)
{
	int c, p;
	for (c = p = 0; c < 31; c += 10, p -= 1)
	{
		glColor3f(0.5, 0.5, 0.5);
		Drawarc(0, 360, m + c, n, 10 + p);
	}
}
void DrawCircle(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < num_segments; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle

		float x = r * cosf(theta);//calculate the x component
		float y = r * sinf(theta);//calculate the y component

		glVertex2f(x + cx - 830, y + cy - 450);//output vertex

	}
	glEnd();
	glFlush();
}
void DrawSemicircle(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < num_segments; i++)
	{
		float theta = 3.1415926f * float(i) / float(num_segments);//get the current angle

		float x = r * cosf(theta);//calculate the x component
		float y = r * sinf(theta);//calculate the y component

		glVertex2f(x + cx - 830, y + cy - 450);//output vertex

	}
	glEnd();
	glFlush();
}
void DrawCloud(float cx, float cy, float r, int num_segments)
{
	glColor3f(1, 1, 1);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < num_segments; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle

		float x = r * cosf(theta);//calculate the x component
		float y = r * sinf(theta);//calculate the y component

		glVertex2f(x + cx, y + cy);//output vertex

	}
	glEnd();
	glFlush();
}

void cloud(int x, int y)
{
	DrawCloud(x, y, 25, 1000);
	DrawCloud(x - 20, y, 20, 1000);
	DrawCloud(x + 20, y, 20, 1000);
	glColor3f(0, 0, 0);
	int s;
	glRasterPos2i(-255, 200);                                                   
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'B');
	glFlush();
}
char e[500] ="                 Energy Source or Illumination (A)                        Radiation and Atmosphere (B)                       Interaction with the Target (C)";
char f[500] ="            Recording of Energy by the Sensor (D)         Transmission, Reception and Processing (E)           Interpretation and Analysis(F)";
void explain2()
{
	glColor3f(0, 0, 0);
	glRecti(-600, 400, 600, 500);

	glColor3f(1, 1, 1);
	int s;
	glRasterPos2i(-580,470);                                                    
	for (s = 0; e[s] != '\0'; s++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, e[s]);
	}
	glRasterPos2i(-580, 430);                                                  
	for (s = 0; f[s] != '\0'; s++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, f[s]);
	}
}

void explain3()
{
	glColor3f(1, 1, 1);
	glRecti(-600, 400, 600, 500);

	glColor3f(0, 0, 0);
	int s;
	glRasterPos2i(-580, 470);                                                   
	for (s = 0; e[s] != '\0'; s++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, e[s]);
	}
	glRasterPos2i(-580, 430);                                              
	for (s = 0; f[s] != '\0'; s++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, f[s]);
	}
}

void frontscreen()
{
	glPushMatrix();
	glTranslatef(-400, -250, 0);
	glClearColor(0.8, 1.0, 0.8, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	int s;
	glColor3f(1.0, 0.3, 0);
	glRasterPos2i(300, 520);                                                    //displays college name
	for (s = 0; college[s] != '\0'; s++)
	{

		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, college[s]);
	}
	glColor3f(1, 0.3, 0);
	glRasterPos2i(200, 450);                                                     //displays dept.
	for (s = 0; dept[s] != '\0'; s++)
	{

		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, dept[s]);
	}
	glColor3f(1.0, 0.0, 0.0);
	glRasterPos2i(320, 380);                                                    //displays project name
	for (s = 0; title[s] != '\0'; s++)
	{

		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, title[s]);
	}

	glRasterPos2i(100, 340);                                                    //displays heading of table
	for (s = 0; heading[s] != '\0'; s++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, heading[s]);
	}
	glColor3f(0.0, 0.0, 1.0);
	glRasterPos2i(330, 310);                                                    //displays 1st row in table
	for (s = 0; row1[s] != '\0'; s++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, row1[s]);
	}
	glColor3f(0.0, 0.0, 1.0);
	glRasterPos2i(300, 270);                                                    //displays 2nd row in table
	for (s = 0; row2[s] != '\0'; s++)
	{

		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, row2[s]);
	}

	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2i(340, 100);                                                    //displays "enter msg"
	for (s = 0; emsg[s] != '\0'; s++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, emsg[s]);
	}

	glPopMatrix();
	glFlush();
}

void drawsun()
{
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	{

		for (int a = 0; a < 360; a++)
		{
			int x = 25 * cos(a);
			int y = 25 * sin(a);
			glVertex2f(x - 450, y + 290);
		}
	}
	glEnd();
	glBegin(GL_LINES);
	{
		for (int a = 0; a < 36; a++)
		{
			float i = 3.14 / 18 * a;
			glVertex2f(30 * cos(i) - 450, 30 * sin(i) + 290);
			glVertex2f(50 * cos(i) - 450, 50 * sin(i) + 290);
		}
	}
	glEnd();

	glColor3f(0, 0, 0);
	int s;
	glRasterPos2i(-455, 285);                                                    
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'A');
	glFlush();
}
void river_boundary()
{
	glColor3f(0.5, 0.5, 0.5);
	glLineWidth(3.0);
	glBegin(GL_LINES);
	glVertex2i(-200, -300);
	glVertex2i(-250, -250);
	glVertex2i(-290, -230);
	glVertex2i(-300, 75);
	glVertex2i(-600, 75);
	glEnd();
	glFlush();
}
void river_bank()
{
	//to make pebbles
	glColor3f(0.1, 0.1, 0.1);
	int y = 520;
	DrawCircle(530, y, 20, 1000);
	DrawCircle(530, y - 30, 20, 1000);
	DrawCircle(530, y - 60, 20, 1000);
	DrawCircle(530, y - 90, 20, 1000);
	DrawCircle(530, y - 120, 20, 1000);
	DrawCircle(530, y - 150, 20, 1000);
	DrawCircle(530, y - 180, 20, 1000);
	DrawCircle(530, y - 210, 20, 1000);
	DrawCircle(530, y - 240, 20, 1000);
	DrawCircle(530, y - 270, 20, 1000);
	DrawCircle(530, y - 300, 20, 1000);
	DrawCircle(560, 200, 20, 1000);
	DrawCircle(590, 180, 20, 1000);
	DrawCircle(620, 150, 20, 1000);
	glFlush();
}
void river() {

	glBegin(GL_POLYGON); // River
	glColor3f(0.2, 0.3, 1.1);
	glVertex2i(-600, -300);//left bottom
	glVertex2i(-200, -300);
	glVertex2i(-250, -250);//industry meeting
	glVertex2i(-290, -230);
	glVertex2i(-300, 90);
	glVertex2i(-600, 90);
	glVertex2i(-430, 90);//emerging
	
	glEnd();
	glColor3f(0, 0, 0);
	int s;
	glRasterPos2i(-450, -240);                                                   
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'c');
	glFlush();
}

void sky() {
	glBegin(GL_POLYGON); //Sky  
	glColor3f(0.69, 0.87, 0.9);//powder blue
	glVertex2i(-600, -300);
	glVertex2i(600, -300);
	glVertex2i(600, 400);
	glVertex2i(-600, 400);
	glEnd();
	glFlush();
}
void hills() {
	//to make water emerging
	glColor3f(0.2, 0.3, 1.1);
	DrawCircle(380, 540, 20, 2000);
	//hills
	glColor3f(0.6, 0.3, 0.1);
	DrawSemicircle(300, 525, 80, 2000); //1
	glFlush();

}
void back_hills()
{
	//hills
	glColor3f(0.6, 0.3, 0.1);
	DrawSemicircle(450, 525, 80, 2000);//2
	//DrawSemicircle(600, 510, 100, 2000);//2
	glFlush();
}
void tree()
{
	//draw ground

	glColor3f(0.2, 0.5, 0.2);
	DrawSemicircle(300, 50, 200, 2000);

	glBegin(GL_POLYGON); //Tree
	glColor3f(.6, 0.3, 0.1);
	glVertex2i(-500, -260);
	glVertex2i(-470, -260);
	glVertex2i(-470, -170);
	glVertex2i(-490, -170);

	glVertex2i(-530, -260);
	glVertex2i(-435, -260);
	glVertex2i(-470, -250);
	glVertex2i(-490, -250);

	glVertex2i(-490, -170);
	glVertex2i(-470, -170);
	glVertex2i(-450, -130);

	glVertex2i(-470, -130);
	glVertex2i(-490, -160);
	glVertex2i(-510, -130);
	glVertex2i(-530, -130);
	glEnd();

	glColor3f(0.0, 0.5, 0.1);
	DrawCircle(320, 350, 35, 2000); //center-left
	DrawCircle(380, 410, 36, 2000);//2
	DrawCircle(300, 400, 40, 2000);//1
	DrawCircle(380, 355, 40, 1000);//top left
	DrawCircle(340, 440, 45, 1000);//5
	DrawCircle(290, 350, 30, 1000);//left corner
	DrawCircle(320, 380, 33, 1000);
	glColor3f(0, 0, 0);
	int s;
	glRasterPos2i(-500, -185);                                                    
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'C');
	glFlush();
}

void drawsquare(int x, int y)
{

	glBegin(GL_POLYGON);
	{
		glVertex2f(x, y);
		glVertex2f(x + 10, y);
		glVertex2f(x + 10, y + 10);
		glVertex2f(x, y + 10);
	}
	glEnd();
}

void drawrect(int x, int y)
{
	glBegin(GL_POLYGON);
	{
		glVertex2f(x, y);
		glVertex2f(x + 20, y);
		glVertex2f(x + 20, y + 10);
		glVertex2f(x, y + 10);
	}
	glEnd();
}
void DrawSatellite()
{
	//orange small part
	glColor3f(1, 0.647, 0);
	glRecti(300, 200, 350, 210);

	//center part
	glColor3f(.502, .502, .502);
	glRecti(280, 200, 370, 100);

	//small whitepart
	glColor3f(1, 1, 1);
	glRecti(300, 80, 350, 100);

	//half tri part
	glBegin(GL_POLYGON);
	{
		glColor3f(1, 0.647, 0);
		glVertex2f(300, 80);
		glVertex2f(350, 80);
		glVertex2f(370, 60);
		glVertex2f(280, 60);
	}
	glEnd();

	//last part
	glColor3f(1, 1, 1);
	glRecti(270, 55, 380, 60);

	//orange left right part
	glColor3f(1, 0.647, 0);
	glRecti(260, 140, 280, 150);
	glRecti(370, 140, 390, 150);

	//dark gray left right part
	glColor3f(.184, .309, .309);
	glRecti(150, 110, 260, 190);
	glRecti(390, 110, 500, 190);

	//receiver part
	glColor3f(1, 1, 1);
	glRecti(323, 30, 327, 55);

	glBegin(GL_POLYGON);
	{

		for (int a = 0; a < 360; a++)
		{
			int x = 10 * cos(a);
			int y = 10 * sin(a);
			glVertex2f(x + 325, y + 22);
		}
	}
	glEnd();

	//red circle
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	{

		for (int a = 0; a < 360; a++)
		{
			int x = 10 * cos(a);
			int y = 10 * sin(a);
			glVertex2f(x + 325, y + 160);
		}
	}
	glEnd();

	drawrect(155, 115);
	drawrect(155, 130);
	drawrect(155, 145);
	drawrect(155, 160);
	drawrect(155, 175);

	drawrect(180, 115);
	drawrect(180, 130);
	drawrect(180, 145);
	drawrect(180, 160);
	drawrect(180, 175);

	drawrect(205, 115);
	drawrect(205, 130);
	drawrect(205, 145);
	drawrect(205, 160);
	drawrect(205, 175);

	drawrect(230, 115);
	drawrect(230, 130);
	drawrect(230, 145);
	drawrect(230, 160);
	drawrect(230, 175);

	drawrect(400, 115);
	drawrect(400, 130);
	drawrect(400, 145);
	drawrect(400, 160);
	drawrect(400, 175);

	drawrect(425, 115);
	drawrect(425, 130);
	drawrect(425, 145);
	drawrect(425, 160);
	drawrect(425, 175);

	drawrect(450, 115);
	drawrect(450, 130);
	drawrect(450, 145);
	drawrect(450, 160);
	drawrect(450, 175);

	drawrect(475, 115);
	drawrect(475, 130);
	drawrect(475, 145);
	drawrect(475, 160);
	drawrect(475, 175);

	glColor3f(1, 1, 1);
	int s;
	glRasterPos2i(325, 125);                                                    
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'D');
	glFlush();
}
void satellite()
{
	glLoadIdentity();
	glTranslatef(270, 340, 0);
	glScalef(0.75, 0.75, 0);
	glRotatef(-40, 0, 0, 1);
	glTranslatef(-150, -110, 0);
	DrawSatellite();
	glLoadIdentity();
}
void industry()
{
	glColor3f(1, 0, 0);
	glLineWidth(2.0);
	glBegin(GL_LINE_LOOP);
	{
		glVertex2f(-250, -250);
		glVertex2f(-250, -160);
		glVertex2f(-225, -180);
		glVertex2f(-225, -160);
		glVertex2f(-200, -180);
		glVertex2f(-200, -160);
		glVertex2f(-175, -180);
		glVertex2f(-175, -160);
		glVertex2f(-150, -180);
		glVertex2f(-150, -250);
	}
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	{
		glVertex2f(-239, -170);
		glVertex2f(-228, -120);
		glVertex2f(-228, -120);
		glVertex2f(-218, -120);
		glVertex2f(-218, -120);
		glVertex2f(-209, -170);

	}
	glEnd();
	glColor3f(1, 0, 0);
	drawsquare(-240, -230);
	drawsquare(-240, -205);
	drawsquare(-217, -230);
	drawsquare(-217, -205);
	drawsquare(-193, -230);
	drawsquare(-193, -205);
	drawsquare(-170, -230);
	drawsquare(-170, -205);
	smoke(-220, -105);
	glFlush();
}
void groupindustries()
{
	industry();
	glLoadIdentity();
	glScalef(0.75, 0.75, 0);
	glTranslatef(280, 290, 0);
	glRotatef(0, 0, 0, 1);
	glTranslatef(-250, -250, 0);
	industry();
	glLoadIdentity();
	glScalef(0.75, 0.75, 0);
	glTranslatef(160, 380, 0);
	glRotatef(0, 0, 0, 1);
	glTranslatef(-250, -250, 0);
	industry();
	glLoadIdentity();
}
void green_lush()
{
	//green lush
	glColor3f(0.48, 0.8, 0.2);
	DrawSemicircle(800, 110, 100, 2000);
	DrawSemicircle(1000, 50, 200, 2000);
	DrawSemicircle(1250, 100, 200, 2000);
	glFlush();
}
void building()
{
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	{
		glVertex2f(50, -250);
		glVertex2f(50, -100);
		glVertex2f(150, -100);
		glVertex2f(150, -250);
		glColor3f(0.86, 0.88, 0.99);
		glVertex2f(200, -200);//back side
		glVertex2f(200, -50);
		glVertex2f(100, -50);
		glVertex2f(50, -100);
	}
	glEnd();

	glColor3f(0.2, 0.1, 1.0);
	drawsquare(65, -230);
	drawsquare(95, -230);
	drawsquare(125, -230);

	drawsquare(65, -200);
	drawsquare(95, -200);
	drawsquare(125, -200);

	drawsquare(65, -170);
	drawsquare(95, -170);
	drawsquare(125, -170);

	drawsquare(65, -140);
	drawsquare(95, -140);
	drawsquare(125, -140);
	glFlush();
}

void groupbuildings()
{
	glLoadIdentity();//1
	glScalef(0.75, 0.75, 0);
	glTranslatef(-200, 120, 0);
	glRotatef(0, 0, 0, 1);
	glTranslatef(50, -250, 0);
	building();
	glLoadIdentity();

	building();//3
	glLoadIdentity();
	glScalef(0.8, 0.8, 0);
	glTranslatef(120, 150, 0);
	glRotatef(0, 0, 0, 1);
	glTranslatef(50, -250, 0);
	building();

	glLoadIdentity();//3
	glScalef(0.8, 0.8, 0);
	glTranslatef(220, 150, 0);
	glRotatef(0, 0, 0, 1);
	glTranslatef(50, -250, 0);
	building();

	glLoadIdentity();//4
	glTranslatef(300, 250, 0);
	glRotatef(0, 0, 0, 1);
	glTranslatef(50, -250, 0);
	building();
	glLoadIdentity();

}

void boat()
{
	glColor3f(0.803, .498, .196);
	glBegin(GL_POLYGON);
	{
		glVertex2f(-350, -20);
		glVertex2f(-360, -53);
		glVertex2f(-440, -50);
		glVertex2f(-450, -20);
	}
	glEnd();

	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLES);
	{
		glVertex2f(-355, -20);
		glVertex2f(-400, -20);
		glVertex2f(-400, 40);
	}
	glEnd();

	glFlush();
}
void arrowsun()
{
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);

	{

		glVertex2f(-470, 270);//tree
		glVertex2f(-500, -80);

		glVertex2f(-440, 260);//industry
		glVertex2f(-250, -190);

		glVertex2f(-420, 270);//builging
		glVertex2f(150, -50);

		glVertex2f(-480, 270);//cloud
		glVertex2f(-570, 210);

	}
	glEnd();

	glBegin(GL_TRIANGLES);
	{
		glVertex2f(-500, -80);
		glVertex2f(-510, -70);
		glVertex2f(-490, -70);

		glVertex2f(-250, -190);
		glVertex2f(-250, -170);
		glVertex2f(-265, -180);

		glVertex2f(150, -50);
		glVertex2f(145, -35);
		glVertex2f(130, -50);

		glVertex2f(-570, 210);
		glVertex2f(-563, 230);
		glVertex2f(-555, 210);
	}
	glEnd();

	glFlush();
}

void arrowsat()
{
	glColor3f(0, 0, 0);

	glBegin(GL_LINES);

	{

		glVertex2f(320, 220);//tree
		glVertex2f(-500, -80);

		glVertex2f(315, 190);//industry
		glVertex2f(-150, -190);

		glVertex2f(370, 190);//builging
		glVertex2f(190, -150);

	}
	glEnd();
	glBegin(GL_TRIANGLES);
	{
		glVertex2f(320, 220);//tree
		glVertex2f(300, 220);
		glVertex2f(310, 200);

		glVertex2f(315, 190);//industry
		glVertex2f(295, 190);
		glVertex2f(310, 170);

		glVertex2f(370, 190);//builging
		glVertex2f(350, 180);
		glVertex2f(370, 170);

	}
	glEnd();

	glFlush();

}

void observation_center()
{
	glLoadIdentity();//1
	glScalef(1.5, 1.5, 0);
	glTranslatef(-170, 320, 0);
	glRotatef(0, 0, 0, 1);
	glTranslatef(50, -250, 0);
	building();

	glLoadIdentity();//2
	glScalef(1.25, 1.25, 0);
	glTranslatef(-10, 270, 0);
	glRotatef(0, 0, 0, 1);
	glTranslatef(50, -250, 0);
	building();
	glFlush();

}
void dish()
{
	glColor3f(0.5, 0.5, 0.5);
	//glLoadIdentity();
	glTranslatef(-75, -70, 0);
	glRotatef(60, 1, 0, 1);
	glTranslatef(75, 50, 0);
	glutWireCone(75, 10, 25, 25);
	glLoadIdentity();

}
void receptors()
{
	glLineWidth(1);
	glColor3f(1, 1, 1);
	//glLoadIdentity();
	glTranslatef(-530, 60, 0);
	glRotatef(60, 1, 0, 1);
	glTranslatef(75, 50, 0);
	glutWireCone(70, 10, 20, 10);
	glLoadIdentity();

	glColor3f(1, 1, 1);//base
	glLoadIdentity();
	//glTranslatef(-1, -2, 4);
	glTranslatef(-500, -250, 4);
	glRotatef(290, 1, 0, 0);
	glScalef(150, 200, 400);
	glutWireCone(.5, 1, 4, 5);
	
	glFlush();
}
void satellite2()
{
	glLoadIdentity();
	glTranslatef(-375, 280, 0);
	//glRotatef(-40, 0, 0, 1);
	glScalef(0.75, 0.75, 0);
	glTranslatef(-150, -110, 0);
	DrawSatellite();
	glLoadIdentity();
	glFlush();
}
void night_sky() {
	glClearColor(0, 0, 0, 1);
	glBegin(GL_POLYGON); //Sky  
	glColor3f(0, 0, 0);//black
	glVertex2i(-600, -300);
	glVertex2i(600, -300);
	glVertex2i(600, 400);
	glVertex2i(-600, 400);
	glFlush();
	glEnd();
}
void arrows3()
{
	glLineWidth(1);
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	{
		glVertex2f(-250, 200);
		glVertex2f(-430, 155);

		glVertex2f(-230, 200);
		glVertex2f(-50, 90);

		glVertex2f(-430, 145);
		glVertex2f(-80, 70);

	}
	glEnd();
	glBegin(GL_TRIANGLES);
	{

		glVertex2f(-415, 165);
		glVertex2f(-430, 155);
		glVertex2f(-400, 150);

		glVertex2f(-50, 110);
		glVertex2f(-50, 90);
		glVertex2f(-75, 90);

		glVertex2f(-80, 90);
		glVertex2f(-80, 70);
		glVertex2f(-100, 60);

	}
	glEnd();
	glFlush();
}

void arrowe3()
{
	glLineWidth(1);
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	{
		glVertex2f(180, 200);
		glVertex2f(120, 50);
	}
	glEnd();
	glBegin(GL_TRIANGLES);
	{
		glVertex2f(160, 190);
		glVertex2f(180, 200);
		glVertex2f(190, 190);
	}
	glEnd();
	glFlush();
}

void hill4()//hills
{
	DrawSemicircle(300, 525, 80, 2000);
	DrawSemicircle(450, 525, 80, 2000);
}

void treebark4()
{
	//tree
	glBegin(GL_POLYGON); //Tree
	//glColor3f(.6, 0.3, 0.1);
	glVertex2i(-500, -260);
	glVertex2i(-470, -260);
	glVertex2i(-470, -170);
	glVertex2i(-490, -170);

	glVertex2i(-530, -260);
	glVertex2i(-435, -260);
	glVertex2i(-470, -250);
	glVertex2i(-490, -250);

	glVertex2i(-490, -170);
	glVertex2i(-470, -170);
	glVertex2i(-450, -130);

	glVertex2i(-470, -130);
	glVertex2i(-490, -160);
	glVertex2i(-510, -130);
	glVertex2i(-530, -130);
	glEnd();
}
void river4()
{
	glLineWidth(3.0);
	glBegin(GL_POLYGON);
	glVertex2f(-600, -300);
	glVertex2i(-200, -300);
	glVertex2i(-300, 75);
	glVertex2i(-600, 75);
	glEnd();
}
void treebranch4()
{
	//lColor3f(0.0, 0.5, 0.1);
	DrawCircle(320, 350, 35, 2000); //center-left
	DrawCircle(380, 410, 36, 2000);//2
	DrawCircle(300, 400, 40, 2000);//1
	DrawCircle(380, 355, 40, 1000);//top left
	DrawCircle(340, 440, 45, 1000);//5
	DrawCircle(290, 350, 30, 1000);//left corner
	DrawCircle(320, 380, 33, 1000);
}
void image()
{
	glColor3f(.56, .56, .56);
	glRectf(-600, -300, -50, 250);
	glColor3f(0.45, 0.45, 0.45);
	river4();
	glColor3f(0.2, 0.2, 0.2);
	hill4();
	glColor3f(0.25, 0.25, 0.25);
	treebark4();
	glColor3f(0.35, 0.35, 0.35);
	treebranch4();
	glColor3f(1, 1, 1);
	int s;
	glRasterPos2i(5, 180);                                                   
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'F');
	glFlush();
}

void viewimage()
{
	glLoadIdentity();
	glTranslated(450, 250, 0);
	glScalef(0.4, .4, 0);
	glTranslated(0, 0, 0);
	image();
}
void fourthscreen()
{
	glPushMatrix();
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);

	char end[40] = "Thank You";
	glColor3f(1,1,1);
	glRasterPos2i(-20,100);                      
	for (int s = 0; end[s] != '\0'; s++)
	{

		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, end[s]);
	}
	glPopMatrix();
	glFlush();

}
void thirdscreen()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	explain3();
	night_sky();
	Sleep(1000);
	glPushMatrix();
	satellite2();
	glPopMatrix();
	Sleep(3000);
	glPushMatrix();
	receptors();
	glPopMatrix();
	Sleep(3000);
	glPushMatrix();
	green_lush();
	observation_center();
	glColor3f(1, 1, 1);
	int s;
	glRasterPos2i(5, 60);                                                    
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
	dish();
	glPopMatrix();
	Sleep(3000);
	arrows3();
	Sleep(3000);
	glPushMatrix();
	viewimage();
	glPopMatrix();
	Sleep(3000);
	arrowe3();

	Sleep(4000);
	fourthscreen();
	glFlush();
}

void secondscreen()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	explain2();
	sky();
	drawsun();
	Sleep(5000);
	cloud(-600, 200);
	cloud(-100, 275);
	cloud(-250, 210);
	cloud(50, 210);
	Sleep(5000);
	river_bank();
	back_hills();
	river();
	hills();
	Sleep(1000);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(-550, -260, 0);
	glTranslatef(500, 260, 0);
	tree();
	glLoadIdentity();
	glPopMatrix();
	river_boundary();
	boat();
	Sleep(1000);
	industry();
	groupindustries();
	glPushMatrix();
	glPopMatrix();
	Sleep(2000);
	aeroplane();
	Sleep(2000);
	green_lush();
	building();
	glPushMatrix();
	groupbuildings();
	glPopMatrix();
	glPushMatrix();
	Sleep(5000);
	satellite();
	glPopMatrix();
	Sleep(1000);
	arrowsun();
	Sleep(5000);
	arrowsat();
	Sleep(5000);
	thirdscreen();
	glFlush();
}
void mymouse(int b, int s, int x, int y)
{
	if (b == GLUT_RIGHT_BUTTON && s == GLUT_DOWN)
		secondscreen();

}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	frontscreen();
	glFlush();
}
int main(int argc, char** argv)
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(1200, 750);				// Set display-window width and height.
	glutCreateWindow("Remote Sensing");
	myinit();
	glutDisplayFunc(display);
	glutMouseFunc(mymouse);
	glutMainLoop();
}