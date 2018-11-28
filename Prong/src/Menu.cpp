#include "Menu.hpp"

using namespace std;

extern GLint status, winner;

void winMessage(GLint winner) {
	string winnerP1 = "PLAYER 1 WINS!!!";
	string winnerP2 = "PLAYER 2 WINS!!!";
	string message;
	float r = 0.0, b = 0.0;
	if (winner == 1) {
		message = winnerP1;
		r = 1.0;
	} else if (winner == 2) {
		message = winnerP2;
		b = 1.0;
	}
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(r, 0.0, b);
	glRasterPos2f(200, 200);
	for (string::size_type i = 0; i < message.size(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, message[i]);
	}
}

void mainMenu (GLint option) {
	switch (option) {
		case 1: { // pause or unpause
			//
		} break;
		case 2: { // reset
		} break;
		case 3: { // quit
			exit(0);
		} break;
	}
	glutPostRedisplay();
}

void scoreMenu(GLint option) {}

void menu () {
	glutCreateMenu(mainMenu);
	glutAddMenuEntry("Pause   ", 1);
	glutAddMenuEntry("Reset   ", 2);
	glutAddMenuEntry("Quit    ", 3);
}
