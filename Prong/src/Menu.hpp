#ifndef SRC_MENU_HPP_
#define SRC_MENU_HPP_

#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

enum GameStatus {
	PAUSED,
	IN_PROGRESS,
	COMPLETE
};

void pauseMessage();
void winMessage();
void mainMenu(GLint option);
void debugMenu(GLint option);
void scoreMenu(GLint option);
void menu ();

#endif
