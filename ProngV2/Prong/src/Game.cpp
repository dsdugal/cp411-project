#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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
GLint status; // 0 = paused, 1 = in progress, 2 = complete
GLint windowHeight = 600, windowWidth = 800, windowPosX = 200, windowPosY = 200;

void display (void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	myCamera.setProjectionMatrix();
	myWorld.drawWorld();
	printf("PENIS \n");
	glFlush();
	glutSwapBuffers();
}

void init (void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);

	ballSpeed = 0;
	paddleSpeed = 0;
	player1Score = 0;
	player2Score = 0;
	status = 0; // should choose options before starting game
	myCamera.setDefaultCamera();
	printf("PNESS \n");
}

void keyboard(unsigned char key, int x, int y){
	if (key == GLUT_KEY_UP){
		y++;
		glutPostRedisplay();
	}
	if (key == GLUT_KEY_DOWN){
		y--;
		glutPostRedisplay();
	}
	if (key == GLUT_KEY_LEFT){
		x--;
		glutPostRedisplay();
	}
	if (key == GLUT_KEY_RIGHT){
		x++;
		glutPostRedisplay();
	}
}


int main (int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(windowPosX, windowPosY);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("A5");
	printf("BIG PINES \n");
	menu();
	init();
	printf("PEEENUs \n");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return EXIT_SUCCESS;
}
