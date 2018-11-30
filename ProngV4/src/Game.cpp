#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
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

void *font = GLUT_BITMAP_TIMES_ROMAN_24;
void *fonts[] =
{
  GLUT_BITMAP_9_BY_15,
  GLUT_BITMAP_TIMES_ROMAN_10,
  GLUT_BITMAP_TIMES_ROMAN_24
};
char defaultMessage[] = "0:0";
char *message = defaultMessage;

void
selectFont(int newfont)
{
  font = fonts[newfont];
  glutPostRedisplay();
}

//void
//selectMessage(int msg)
//{
//  switch (msg) {
//  case 1:
//    message = "abcdefghijklmnop";
//    break;
//  case 2:
//    message = "ABCDEFGHIJKLMNOP";
//    break;
//  }
//}

void
tick(void)
{
  glutPostRedisplay();
}

void
output(int x, int y, char *string)
{
  int len, i;

  glRasterPos2f(x, y);
  len = (int) strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font, string[i]);
  }
}

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
	output(windowWidth / 2 - 10, windowHeight - 15, message);
	myCamera.setProjectionMatrix();
	myWorld.drawWorld();
	glFlush();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, w, h, 0);
  glMatrixMode(GL_MODELVIEW);
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
	glutReshapeFunc(reshape);
	glutIdleFunc(tick);
	glutKeyboardFunc(inputP1);
	glutSpecialFunc(inputP2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return EXIT_SUCCESS;
}
