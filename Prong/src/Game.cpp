#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include "Board.hpp"
#include "Camera.hpp"
#include "Menu.hpp"
#include "World.hpp"

const int PADDLE_CEILING = -6;
const int PADDLE_FLOOR = 4;

Camera myCamera;
World myWorld;

GLint bSpeed, pSpeed;
GLint scoreP1, scoreP2;
GLint status, winner;
GLint windowHeight = 800, windowWidth = 1600, windowPosX = 200, windowPosY = 200;
int temp;

void inputP1(unsigned char key, int x, int y) {
	GLint direction = 0;
	if (key == 'w'){
		direction = -1;
		if (myWorld.paddleP1->x_pos >= PADDLE_FLOOR){
			myWorld.paddleP1->x_pos += direction;
		}
	} else if (key == 's'){
		direction = 1;
		if (myWorld.paddleP1->x_pos <= PADDLE_CEILING){
			myWorld.paddleP1->x_pos += direction;
		}
	}
	if (myWorld.paddleP1->x_pos <= PADDLE_CEILING){
		// paddle 1 hitting ceiling
	}
	else if (myWorld.paddleP1->x_pos >= PADDLE_FLOOR){
		// paddle 1 hitting floor
	}
	else {
		myWorld.paddleP1->translate(direction * pSpeed, 0, 0);
	}

	if (direction != 0) {
		glutPostRedisplay();
	}
}

void inputP2(int key, int x, int y) {
	GLint direction = 0;
	if (key == GLUT_KEY_UP){
		direction = -1;
		if (myWorld.paddleP2->x_pos >= PADDLE_FLOOR){
			myWorld.paddleP2->x_pos += direction;
		}
	} else if (key == GLUT_KEY_DOWN){
		direction = 1;
		if (myWorld.paddleP2->x_pos <= PADDLE_CEILING){
			myWorld.paddleP2->x_pos += direction;
		}
	}
	if (myWorld.paddleP2->x_pos <= -6){
		// paddle 2 hitting ceiling
	}
	else if (myWorld.paddleP2->x_pos >= 4){
		// paddle 2 hitting floor
	}
	else {
		myWorld.paddleP2->translate(direction * pSpeed, 0, 0);
	}

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
