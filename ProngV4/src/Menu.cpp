#include <iostream>
#include <windows.h>
#include <MMSystem.h>
#include "Menu.hpp"

using namespace std;

extern GLint scoreP1, scoreP2, scoreMax;
extern GLint status, winner, music;
extern World myWorld;
extern Scoreboard myScore;

// for debugging only
void setScore(GLint updateP1, GLint updateP2) {
	scoreP1 = updateP1;
	scoreP2 = updateP2;
}

void updateScore(GLint updateP1, GLint updateP2) {
	scoreP1 += updateP1;
	scoreP2 += updateP2;
	if (scoreP1 >= scoreMax) {
		status = COMPLETE;
		winner = 1;
	}
	if (scoreP2 >= scoreMax) {
		status = COMPLETE;
		winner = 2;
	}
}

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
			break;
		}
		case 2: { // reset
			status = IN_PROGRESS;
			winner = 0;
			scoreP1 = 0;
			scoreP2 = 0;
			myScore.resetScoreboard();
			myWorld.resetWorld();
			break;
		}
		case 3: { // quit
			exit(0);
			break;
		}
	}
	glutPostRedisplay();
}

void debugMenu(GLint option) {
	scoreMax = 10;
	status = DEBUG;
	switch (option) {
		case 1: {
			status = COMPLETE;
			winner = 1;
		} break;
		case 2: {
			status = COMPLETE;
			winner = 2;
		} break;
		case 3: {
			setScore(1, 1);
		} break;
		case 4: {
			setScore(2, 2);
		} break;
		case 5: {
			setScore(3, 3);
		} break;
		case 6: {
			setScore(4, 4);
		} break;
		case 7: {
			setScore(5, 5);
		} break;
		case 8: {
			setScore(6, 6);
		} break;
		case 9: {
			setScore(7, 7);
		} break;
		case 10: {
			setScore(8, 8);
		} break;
		case 11: {
			setScore(9, 9);
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
				scoreMax = 9;
			} break;
		}
	}
}

void musicMenu(GLint option){
	switch (option) {
		case 1: {
			PlaySound("PongTheme.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);;
		} break;
		case 2: {
			PlaySound("Culture.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);;
		} break;
		case 3: {
			PlaySound(NULL, NULL, 0);
		} break;
	}
}
void menu () {
	GLint s = glutCreateMenu(scoreMenu);
	glutAddMenuEntry("Max Score: 3", 1);
	glutAddMenuEntry("Max Score: 5", 2);
	glutAddMenuEntry("Max Score: 7", 3);
	glutAddMenuEntry("Max Score: 9", 4);
	GLint d = glutCreateMenu(debugMenu);
	glutAddMenuEntry("Set Winner: Player 1",  1);
	glutAddMenuEntry("Set Winner: Player 2",  2);
	glutAddMenuEntry("Test Scoreboard: 1  ",  3);
	glutAddMenuEntry("Test Scoreboard: 2  ",  4);
	glutAddMenuEntry("Test Scoreboard: 3  ",  5);
	glutAddMenuEntry("Test Scoreboard: 4  ",  6);
	glutAddMenuEntry("Test Scoreboard: 5  ",  7);
	glutAddMenuEntry("Test Scoreboard: 6  ",  8);
	glutAddMenuEntry("Test Scoreboard: 7  ",  9);
	glutAddMenuEntry("Test Scoreboard: 8  ", 10);
	glutAddMenuEntry("Test Scoreboard: 9  ", 11);
	GLint m = glutCreateMenu(musicMenu);
	glutAddMenuEntry("Pong Theme ",  1);
	glutAddMenuEntry("Soothing ",  2);
	glutAddMenuEntry("Music Off",  3);
	glutCreateMenu(mainMenu);
	glutAddMenuEntry("Un/pause", 1);
	glutAddMenuEntry("Reset   ", 2);
	glutAddSubMenu("Score   ",   s);
	glutAddSubMenu("Debug   ",   d);
	glutAddSubMenu("Music   ",   m);
	glutAddMenuEntry("Quit    ", 3);
}
