// MMSP_Lab5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <Windows.h>
#include <glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cstdio>
#include <string>

int texImageWidth;
int texImageHeight;
int window;
static GLuint texName;			
int anglex = 0, angley = 0, anglez = 0;	

void init(void)
{
	float light_ambient[4] = { 0.1, 0.1, 0.1, 1.0 }; 	
	float light_diffuse[4] = { 1.0, 1.0, 0.9, 1.0 }; 	
														
	float light_position[4] = { 1.0, 1.0, 1.0 , 0.0 };

	glClearColor(0, 0, 0, 0.0);
	glShadeModel(GL_FLAT);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHT0);


	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glGenTextures(1, &texName);


	glBindTexture(GL_TEXTURE_2D, texName);		
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glEnable(GL_TEXTURE_2D);
}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glRotatef(anglex, 1.0, 0.0, 0.0);		
	glRotatef(angley, 0.0, 1.0, 0.0);		
	glRotatef(anglez, 0.0, 0.0, 1.0);		

	glutSolidTorus(0.5, 2, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glRotatef(anglex, 1.0, 0.0, 0.0);
	glRotatef(angley+90, 0.0, 1.0, 0.0);
	glRotatef(anglez, 0.0, 0.0, 1.0);

	glTranslatef(0.0, 1.5, 0.0);
	glutSolidTorus(0.5, 2, 30, 30);
	glPopMatrix();
	glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'x':
		anglex = (anglex + 3) % 360;
	
		break;
	case 'X':
		anglex = (anglex - 3) % 360;
	
		break;
	case 'y':
		angley = (angley + 3) % 360;
		
		break;
	case 'Y':
		angley = (angley - 3) % 360;
	
		break;
	case 'z':
		anglez = (anglez + 3) % 360;
	
		break;
	case 'Z':
		anglez = (anglez - 3) % 360;
		
		break;
	case 'r':
		anglex = angley = anglez = 0;
		break;
	case 27: 
		glutDestroyWindow(window);
		exit(0);
	}
	glutPostRedisplay();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-4.0, 4.0, -4.0 * (GLfloat)h / (GLfloat)w,
		4.0 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(5, 0, 0, 0, 0, 0, 0, 0, 1);
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	window = glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}