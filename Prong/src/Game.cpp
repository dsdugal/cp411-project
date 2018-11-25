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

GLint ballSpeed;
GLint paddleSpeed;
GLint player1Score;
GLint player2Score;
GLint status; // -1 = paused, 0 = in progress, 1 = complete
GLint windowHeight = 600, windowWidth = 800, windowPosX = 200, windowPosY = 200;

void init (void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	ballSpeed = 0;
	paddleSpeed = 0;
	player1Score = 0;
	player2Score = 0;
	status = -1; // should choose options before starting game
}

void display (void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	myWorld.drawWorld();
	glFlush();
	glutSwapBuffers();
}

int main (int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(windowPosX, windowPosY);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("A5");
	menu();
	init();
	glutDisplayFunc(display);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return EXIT_SUCCESS;
}
