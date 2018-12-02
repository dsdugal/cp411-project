#include "Menu.hpp"

using namespace std;

extern GLint scoreMax;
extern GLint status, winner;

void pauseMessage() {
	GLfloat x = 0.0, y = 0.0, z = 0.5;
	char *message = "GAME PAUSED";
	glRasterPos3f(x, y, z);
	for (; *message != '\0'; message++) {
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *message);
	}
}

void winMessage() {
	GLfloat x = 0.0, y = 0.0, z = 0.5;
	char *message;
	if (winner == 1) {
		message = "PLAYER 1 WINS!";
	} else {
		message = "PLAYER 2 WINS!";
	}
	glRasterPos3f(x, y, z);
	for (; *message != '\0'; message++) {
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *message);
	}
}

void mainMenu (GLint option) {
	switch (option) {
		case 1: { // pause or un-pause
			if (status == PAUSED) {
				status = IN_PROGRESS;
			} else if (status == IN_PROGRESS) {
				status = PAUSED;
			}
		} break;
		case 2: { // reset
			//
		} break;
		case 3: { // quit
			exit(0);
		} break;
	}
	glutPostRedisplay();
}

void debugMenu(GLint option) {
	switch (option) {
		case 1: {
			status = COMPLETE;
			winner = 1;
		} break;
		case 2: {
			status = COMPLETE;
			winner = 2;
		} break;
	}
}

void scoreMenu(GLint option) {
	if (status == PAUSED) {
		switch (option) {
			case 1: {
				scoreMax = 3;
			} break;
			case 2: {
				scoreMax = 5;
			} break;
			case 3: {
				scoreMax = 7;
			} break;
			case 4: {
				scoreMax = 10;
			} break;
		}
	}
}

void menu () {
	GLint s = glutCreateMenu(scoreMenu);
	glutAddMenuEntry("Max Score: 3 ", 1);
	glutAddMenuEntry("Max Score: 5 ", 2);
	glutAddMenuEntry("Max Score: 7 ", 3);
	glutAddMenuEntry("Max Score: 10", 4);
	GLint d = glutCreateMenu(debugMenu);
	glutAddMenuEntry("Set Winner: Player 1", 1);
	glutAddMenuEntry("Set Winner: Player 2", 2);
	glutCreateMenu(mainMenu);
	glutAddMenuEntry("Un/pause", 1);
	glutAddMenuEntry("Reset   ", 2);
	glutAddSubMenu("Score   ",   s);
	glutAddSubMenu("Debug   ",   d);
	glutAddMenuEntry("Quit    ", 3);
}
