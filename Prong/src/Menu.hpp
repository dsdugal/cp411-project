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

void winMessage(GLint winner);
void mainMenu(GLint option);
void scoreMenu(GLint option);
void menu ();

#endif
