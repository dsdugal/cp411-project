#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include "Board.hpp"
#include "Camera.hpp"
#include "Menu.hpp"
#include "World.hpp"

Camera myCamera;
World myWorld;

GLint bSpeed, pSpeed;
GLint scoreP1, scoreP2;
GLint status, winner;
GLint windowHeight = 800, windowWidth = 1200, windowPosX = 200, windowPosY = 200;

void inputP1(unsigned char key, int x, int y) {
	GLint direction = 0;
	if (key == 'w'){
		direction = -1;
	} else if (key == 's'){
		direction = 1;
	}
	myWorld.paddleP1->translate(direction * pSpeed, 0, 0);
	if (direction != 0) {
		glutPostRedisplay();
	}
}

void inputP2(int key, int x, int y) {
	GLint direction = 0;
	if (key == GLUT_KEY_UP){
		direction = -1;
	} else if (key == GLUT_KEY_DOWN){
		direction = 1;
	}
	myWorld.paddleP2->translate(direction * pSpeed, 0, 0);
	if (direction != 0) {
		glutPostRedisplay();
	}
}

void init (void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	bSpeed = DEFAULT_BALL_SPEED;
	pSpeed = DEFAULT_PADDLE_SPEED;
	scoreP1 = 0;
	scoreP2 = 0;
	status = PAUSED; // should choose options before starting game
	winner = 0;
}

void display (void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	myCamera.setProjectionMatrix();
	myWorld.drawWorld();
	glFlush();
	glutSwapBuffers();
}

int main (int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(windowPosX, windowPosY);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("Prong");
	menu();
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(inputP1);
	glutSpecialFunc(inputP2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return EXIT_SUCCESS;
}
