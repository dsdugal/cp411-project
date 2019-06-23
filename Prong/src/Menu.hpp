#ifndef SRC_MENU_HPP_
#define SRC_MENU_HPP_

#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "World.hpp"

enum GameStatus {
	PAUSED,
	IN_PROGRESS,
	COMPLETE,
	DEBUG
};

void setScore(GLint updateP1, GLint updateP2);
void updateScore(GLint updateP1, GLint updateP2);
void pauseMessage();
void winMessage();
void mainMenu(GLint option);
void debugMenu(GLint option);
void scoreMenu(GLint option);
void musicMenu(GLint option);
void menu ();

#endif
