//============================================================================
// Name        : ProngV1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
//#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <windows.h>
#include <conio.h>
#include <sstream>
#include <math.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include "GL/freeglut.h"

#include "Racket.hpp"
#include "Menu.hpp"

//#pragma comment(lib, "OpenGL32.lib")

GLint winWidth = 600;
GLint winHeight = 400;
GLint interval = 1000 / 60;
GLint xbegin = 0; // global variable to store the first mouse x coordainte
GLint render_mode = 0; 	//mode -> 0 = 2D, 1 = 3D
GLint game_mode = 0;		//0 = pong, 1 = air hockey, 2 = foosball
GLint texture_option = 0;   // texture option
GLint difficulty = 0;	//0 = easy, 1 = normal, 2 = hard, 3 = insane

GLint score_left = 0;
GLint score_right = 0;

Racket myLeftRacket;
Racket myRightRacket;

//using namespace std;
void init(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel(GL_SMOOTH);

//	//initialize GLSL
//	ProgramObject = InitShader( "vertexshader.txt", "fragmentshader.txt" );
//	glUseProgram(0);  //disable GLSL shader

//	myCamera.setDefaultCamera();       // initialize camera
}

void mouseAction(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		xbegin = x;
		printf("left click \n");
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		//
	}

	glutPostRedisplay();
}

void mouseMotion(GLint x, GLint y) {
	//do something
	glutPostRedisplay();
}

std::string int2str(int x) {
    // converts int to string
    std::stringstream ss;
    ss << x;
    return ss.str( );
}

void drawScore(float x, float y, std::string text) {
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_8_BY_13, (const unsigned char*)text.c_str());
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glLoadIdentity();
//	glColor3f(1.0f, 1.0f, 1.0f);

	//draw 2d rackets
//	myLeftRacket.draw();

//	myRightRacket.x_position = winWidth - myRightRacket.width - 10;
//	myRightRacket.x_position = 50;
//	myRightRacket.draw();

//	drawScore(winWidth / 2 - 10, winHeight - 15, int2str(score_left) + ":" + int2str(score_right));

	glFlush();
	glutSwapBuffers();
}

void update(int value){
	glutTimerFunc(interval, update, 0);
	   // Redisplay frame
	glutPostRedisplay();
}

void winReshapeFcn(GLint newWidth, GLint newHeight) {
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	winWidth = newWidth;
	winHeight = newHeight;
}

int main(int argc, char** argv) {
	setvbuf(stdout, NULL, _IONBF, 0);  //used for prompt Eclipse console output
	setvbuf(stderr, NULL, _IONBF, 0);
	ShowWindow(FindWindowA("ConsoleWindowClass", NULL), false);  //used to hide console

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Prong V1");

//		glewInit(); // for GSLS

	menu();
	init();
	glutDisplayFunc(display);
	glutTimerFunc(interval, update, 0);
	glutMotionFunc(mouseMotion);
	glutMouseFunc(mouseAction);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
