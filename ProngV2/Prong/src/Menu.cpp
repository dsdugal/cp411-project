#include "Menu.hpp"

void menu () {
	glutCreateMenu(mainMenu);
	glutAddMenuEntry("Pause   ", 1);
	glutAddMenuEntry("Reset   ", 2);
	glutAddMenuEntry("Quit    ", 3);
}

void mainMenu (GLint option) {
	switch (option) {
		case 1: { // pause or unpause
			//
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
