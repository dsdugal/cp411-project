#ifndef MENU_HPP_
#define MENU_HPP_


//#include <GL/glew.h>
#include <GL/glut.h>
//#include "GL/glaux.h" // for reading bmp files


#include "Racket.hpp"
#include "Ball.hpp"


void menu();
void mainMenu(GLint option);
void MCTransMenu(GLint transOption);
void GameModeMenu(GLint option);
void RenderMenu(GLint option);
void DifficultyMenu(GLint option);
void TextureMenu(GLint option);

//void move();


#endif
