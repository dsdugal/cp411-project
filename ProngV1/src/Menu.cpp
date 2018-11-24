#include "Menu.hpp"
#include <stdlib.h>
#include <stdio.h>

extern GLint render_mode; 	//mode -> 0 = 2D, 1 = 3D
extern GLint game_mode;		//0 = pong, 1 = air hockey, 2 = foosball
extern GLint texture_option;   // texture option
extern GLint difficulty;

void menu() {
	printf("main menu \n");
	//3 options to choose from
	GLint GameMode_Menu = glutCreateMenu(GameModeMenu);
	glutAddMenuEntry(" Pong ", 1);
	glutAddMenuEntry(" Air Hockey ", 2);
	glutAddMenuEntry(" Foosball ", 3);

	//choice of 2D or 3D
	GLint Render_Menu = glutCreateMenu(RenderMenu);
	glutAddMenuEntry(" 2D ", 1);
	glutAddMenuEntry(" 3D ", 2);

	//difficulty menu
	GLint Difficulty_Menu = glutCreateMenu(DifficultyMenu);
	glutAddMenuEntry(" Easy ", 1);
	glutAddMenuEntry(" Normal ", 2);
	glutAddMenuEntry(" Hard", 3);
	glutAddMenuEntry(" Insane ", 4);

	//Choice of background//texture
	GLint Texture_Menu = glutCreateMenu(TextureMenu);
	glutAddMenuEntry(" Regular", 1);


	glutCreateMenu(mainMenu);	//create the main menu
	glutAddMenuEntry(" Reset ", 1);
	glutAddSubMenu(" Game Mode", GameMode_Menu);
	glutAddSubMenu(" Render Mode", Render_Menu);
	glutAddSubMenu(" Difficulty", Difficulty_Menu);
	glutAddSubMenu(" Texture", Texture_Menu);

	glutAddMenuEntry(" Quit", 2);
}

void mainMenu(GLint option) {
	glutPostRedisplay();
}

void GameModeMenu(GLint option){
	game_mode = option;
	glutPostRedisplay();
}

void RenderMenu(GLint option){
	render_mode = option;
	glutPostRedisplay();
}

void DifficultyMenu(GLint option){
	difficulty = option;
	glutPostRedisplay();
}

void TextureMenu(GLint option){
	texture_option = option;
	glutPostRedisplay();
}

