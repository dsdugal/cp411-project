#include "glsl/Angel.h"
#include <GL/glew.h>
#include <GL/glut.h>
#include "GL/glaux.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <MMSystem.h>
#include "Board.hpp"
#include "Camera.hpp"
#include "Menu.hpp"
#include "World.hpp"
#include "pixmap/RGBpixmap.h"

const int PADDLE_CEILING = -5;
const int PADDLE_FLOOR = 4;

Camera myCamera;
Scoreboard myScore;
World myWorld;

GLfloat r = 0.0, g = 0.0, b = 0.0;
GLint pSpeed;
GLfloat bSpeed;
GLint scoreP1, scoreP2, scoreMax;
GLint status, winner;
GLint music;	//music = 0 is sound off
GLint reset;
GLint windowHeight = 800, windowWidth = 1600, windowPosX = 200, windowPosY = 200;

GLuint ProgramObject; // GLSL program object
RGBpixmap pix[4];    // make 4 (empty) pixmaps

void inputP1(unsigned char key, int x, int y) {
	if (status == IN_PROGRESS) {
		GLint direction = 0;
		if (key == 'w'){
			direction = -1;
			if (myWorld.paddleP1->x_pos >= PADDLE_FLOOR){
				myWorld.paddleP1->x_pos += direction;
			}
		} else if (key == 's'){
			direction = 1;
			if (myWorld.paddleP1->x_pos <= PADDLE_CEILING){
				myWorld.paddleP1->x_pos += direction;
			}
		}
		if (myWorld.paddleP1->x_pos <= PADDLE_CEILING){
			// paddle 1 hitting ceiling
		} else if (myWorld.paddleP1->x_pos >= PADDLE_FLOOR){
			// paddle 1 hitting floor
		} else {
			myWorld.paddleP1->translate(direction * pSpeed, 0, 0);
		}
		if (direction != 0) {
			glutPostRedisplay();
		}
	}
}

void inputP2(int key, int x, int y) {
	if (status == IN_PROGRESS) {
		GLint direction = 0;
		if (key == GLUT_KEY_UP){
			direction = -1;
			if (myWorld.paddleP2->x_pos >= PADDLE_FLOOR){
				myWorld.paddleP2->x_pos += direction;
			}
		} else if (key == GLUT_KEY_DOWN){
			direction = 1;
			if (myWorld.paddleP2->x_pos <= PADDLE_CEILING){
				myWorld.paddleP2->x_pos += direction;
			}
		}
		if (myWorld.paddleP2->x_pos <= PADDLE_CEILING){
			// paddle 2 hitting ceiling
		} else if (myWorld.paddleP2->x_pos >= PADDLE_FLOOR){
			// paddle 2 hitting floor
		} else {
			myWorld.paddleP2->translate(direction * pSpeed, 0, 0);
		}
		if (direction != 0) {
			glutPostRedisplay();
		}
	}
}

void init (void) {
	PlaySound("PongTheme.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
	glClearColor(0.0, 0.0, 0.0, 1.0);

//	glEnable(GL_LINE_SMOOTH);
//	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
//	glEnable(GL_BLEND);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	glShadeModel(GL_SMOOTH);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

//	glDisable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_TEXTURE_2D);
//	glEnable(GL_CULL_FACE);
//	glEnable(GL_NORMALIZE);

	bSpeed = DEFAULT_BALL_SPEED;
	pSpeed = DEFAULT_PADDLE_SPEED;
	scoreP1 = 0;
	scoreP2 = 0;
	scoreMax = 10;
	status = PAUSED; // should choose options before starting game
	winner = 0;
	reset = 0;

	ProgramObject = InitShader( "vertexshader.txt", "fragmentshader.txt" );
	glUseProgram(0);

	pix[0].readBMPFile("ball.bmp");
	pix[0].setTexture(2001);
	pix[1].readBMPFile("board.bmp");
	pix[1].setTexture(2002);
	pix[2].readBMPFile("player1.bmp");
	pix[2].setTexture(2003);
	pix[3].readBMPFile("player2.bmp");
	pix[3].setTexture(2004);

	myWorld.paddleP1->textureID = 2003;
	myWorld.paddleP2->textureID = 2004;
	myWorld.ball->textureID = 2001;

	myWorld.board->topLeft->textureID = 2002;
	myWorld.board->topMiddle->textureID = 2002;
	myWorld.board->topRight->textureID = 2002;
	myWorld.board->leftTop->textureID = 2002;
	myWorld.board->leftBottom->textureID = 2002;
	myWorld.board->rightTop->textureID = 2002;
	myWorld.board->rightBottom->textureID = 2002;
	myWorld.board->bottom->textureID = 2002;
	myWorld.board->surface->textureID = 2002;

}

void display (void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//PlaySound("ToT.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
	myCamera.setProjectionMatrix();
	if (status != DEBUG && status != COMPLETE) {
		glEnable(GL_DEPTH_TEST);
		myWorld.drawWorld();
	}
	glDisable(GL_DEPTH_TEST);
	myScore.drawScore(scoreP1, scoreP2);
	if (status == PAUSED) {
		pauseMessage();
	} else if (status == COMPLETE && winner > 0) {
		if (winner == 1) {
			r = 1.0; b = 0.0;
		} else if (winner == 2) {
			r = 0.0; b = 1.0;
		}
		glColor3f(r, g, b);
		winMessage();
		glColor3f(0.0, 0.0, 0.0);
	}
	glutPostRedisplay();
	glFlush();
	glutSwapBuffers();
}

bool hitPaddle(Sphere* ball){
    if(myWorld.ball->z_pos <= -4.5 || myWorld.ball->z_pos >= 4.5){
        GLint paddleRad = 2;
        if(myWorld.ball->z_pos >= -2){	//what is negative 2?
            if(abs(myWorld.ball->x_pos - myWorld.paddleP1->x_pos) < paddleRad && abs(myWorld.ball->y_pos - myWorld.paddleP1->y_pos) < paddleRad){
                myWorld.paddleP1->hit = true;
                return true;
            }
        }

        else{
            if(abs(myWorld.ball->x_pos - myWorld.paddleP2->x_pos) < paddleRad && abs(myWorld.ball->y_pos - myWorld.paddleP2->y_pos) < paddleRad){
                myWorld.paddleP2->hit = true;
                return true;
            }
        }
    }
    else{
        return false;
    }
}

void updateBall(int millisec){
	myWorld.ball->translate(myWorld.ball->x_pos*bSpeed*5, myWorld.ball->y_pos*bSpeed*5, myWorld.ball->z_pos*bSpeed*5);
	//bSpeed += 0.0003;
	if (hitPaddle(myWorld.ball)){	//hits paddles
		myWorld.ball->z_pos *= -1;
	}
	if (myWorld.ball->x_pos < -6.0 || myWorld.ball->x_pos > 5.5){	//hits top or bottom wall
		//printf("hit top/bottom wall \n");
		myWorld.ball->x_pos *= -1;
		//printf("x = %f \n", myWorld.ball->x_pos);
	}
	else if (myWorld.ball->z_pos < -5.35 || myWorld.ball->z_pos > 5.35){	//hits left or right wall
		myWorld.ball->z_pos *= -1;
		//printf("hit right/left wall \n");
	}
	glutTimerFunc(millisec, updateBall, millisec);
	glutPostRedisplay();
}

int main (int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(windowPosX, windowPosY);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("Prong");
	glewInit();
	menu();
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(inputP1);
	glutSpecialFunc(inputP2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutTimerFunc( 5, updateBall, 5 );
	glutMainLoop();
	return EXIT_SUCCESS;
}
