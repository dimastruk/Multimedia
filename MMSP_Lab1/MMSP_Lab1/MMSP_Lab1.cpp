// MMSP_Lab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <Windows.h>
#include <glut.h>
#include <string>
#include <time.h>

using namespace std;

int interval = 1000;
const int DisplayWidth = 500;
const int DisplayHeight = 400; 

int milliseconds = 0, stop_milliseconds = 0;
int seconds = 0, stop_seconds = 0;
int minutes = 0, stop_minutes = 0;

int len_milliseconds = 0, len_milliseconds2 = 0;
int len_seconds = 0, len_seconds2 = 0;
int len_minutes = 0, len_minutes2 = 0;

string str_milliseconds, str_milliseconds2;
string str_seconds, str_seconds2;
string str_minutes, str_minutes2;

void Text2();

void processNormalKeys(unsigned char key, int x, int y) {
	if (key == 32)
	{
		stop_milliseconds = milliseconds;
		stop_seconds = seconds;
		stop_minutes = minutes;
		milliseconds = 0;
		seconds = 0;
		minutes = 0;
		interval = 1000;
	}

	if (key == 97)
	{
		interval += 50;
	}

	if (key == 100)
	{
		if(interval>=100)
		interval -= 50;
	}
}

void Text()
{
	str_milliseconds = to_string(milliseconds);
	str_seconds = to_string(seconds);
	str_minutes = to_string(minutes);

	glColor3f(0.0, 0.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	gluOrtho2D(-180, 700, -500, 500);

	if (milliseconds < 10)
		str_milliseconds = "0" + to_string(milliseconds);

	if (seconds < 10)
		str_seconds = "0" + to_string(seconds);

	if (minutes < 10)
		str_minutes = "0" + to_string(minutes);

	len_milliseconds = str_milliseconds.length();
	len_seconds = str_seconds.length();
	len_minutes = str_minutes.length();

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	for (int i = 0; i < len_minutes; i++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str_minutes[i]);
	}

	glutStrokeCharacter(GLUT_STROKE_ROMAN, ':');

	for (int i = 0; i < len_seconds; i++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str_seconds[i]);
	}

	glutStrokeCharacter(GLUT_STROKE_ROMAN, ':');

	for (int i = 0; i < len_milliseconds; i++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, str_milliseconds[i]);
	}

	glPopMatrix();
	
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	Sleep(interval/100);

	milliseconds++;

	if (milliseconds == 100)
	{
		milliseconds = 0;
		seconds++;
	}

	if (seconds == 60)
	{
		seconds = 0;
		minutes++;
	}

	if (minutes == 60)
		minutes = 0;

	Text2();
}

void Text2()
{
	str_milliseconds2 = to_string(stop_milliseconds);
	str_seconds2 = to_string(stop_seconds);
	str_minutes2 = to_string(stop_minutes);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	if (stop_milliseconds < 10)
		str_milliseconds2 = "0" + to_string(stop_milliseconds);

	if (stop_seconds < 10)
		str_seconds2 = "0" + to_string(stop_seconds);

	if (stop_minutes < 10)
		str_minutes2 = "0" + to_string(stop_minutes);

	len_milliseconds2 = str_milliseconds2.length();
	len_seconds2 = str_seconds2.length();
	len_minutes2 = str_minutes2.length();

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glColor3f(0.0, 0.0, 0.0);
	
	gluOrtho2D(0, 300, 0, 300);
	glRasterPos2i(5, 5);

	for (int i = 0; i < len_minutes2; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str_minutes2[i]);
	}

	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ':');

	for (int i = 0; i < len_seconds2; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str_seconds2[i]);
	}

	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ':');

	for (int i = 0; i < len_milliseconds2; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str_milliseconds2[i]);
	}

	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void Rectangle()
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.8, -0.3);
	glVertex2f(0.8, -0.3);
	glVertex2f(0.8, 0.5);
	glVertex2f(-0.8, 0.5);
	glEnd();
}

void Rectangle2()
{
	glColor3f(0.55, 0.60, 0.52);
	glBegin(GL_POLYGON);
	glVertex2f(-0.7, -0.2);
	glVertex2f(0.7, -0.2);
	glVertex2f(0.7, 0.4);
	glVertex2f(-0.7, 0.4);
	glEnd();
}



void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.99, 1.0);
	
	Rectangle();
	Rectangle2();
	Text();

	glutSwapBuffers();
}

void menu(int id)
{
	switch (id)
	{
	case 1: 
		MessageBoxA(0, "Клавіші:\nЩоб обнулити секундомір - SPACE\nЩоб сповільнити секундомір - A\nЩоб пришвидшити секундомір - D", "Довідка", MB_OK);
		break;
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(300, 150);
	glutInitWindowSize(DisplayWidth, DisplayHeight);
	glutCreateWindow("Цифровий секундомір");

	glutCreateMenu(menu);
	glutAddMenuEntry("Довідка", 1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutDisplayFunc(Display); // Функція відображення
	glutIdleFunc(Display); // Функція, яка викликається в режимі очікування

	glutKeyboardFunc(processNormalKeys);

	glutMainLoop();
    return 0;
}

