#include "World.hpp"

World::World() {
	board = new Board();
	paddleP1 = new Paddle();
	paddleP1->scaleDown(0.9);
	paddleP1->translate(-1, 0, 4.5);
	paddleP2 = new Paddle();
	paddleP2->scaleDown(0.9);
	paddleP2->translate(-1, 0, -4.5);
	ball = new Ball();
	ball->translate(-1, 0, 0);
}

World::~World(){
	delete board;
	delete paddleP1;
	delete paddleP2;
	delete ball;
}

void World::drawWorld() {
	board->drawBoard();
	paddleP1->draw();
	paddleP2->draw();
	ball->draw();
	ball->update();
}

//void World::updateBall() {
//	ball->x_pos += ball->speed;
//	ball->y_pos += ball->speed;
//	ball->z_pos += ball->speed;
//
//	if(ball->x_pos <= board->topMiddle->x_pos){	//x position of top middle, top right and top left
//		ball->speed *= -1;
//		ball->x_pos *= ball->speed;
//	}
//	if(ball->x_pos >= board->bottom->x_pos){	//x position of bottom
//	    ball->speed *= -1;
//		   //translate(x_pos * speed, y_pos, z_pos);
//	   ball->x_pos *= ball->speed;
//	}
//	if(ball->z_pos >= board->leftBottom->z_pos && ball->y_pos == board->leftBottom->y_pos){	//z and y position of left walls
//		ball->speed *= -1;
//		    //translate(x_pos, y_pos, z_pos * speed);
//		ball->z_pos *= ball->speed;
//	}
//	if(ball->z_pos <= board->rightBottom->z_pos && ball->y_pos == board->rightBottom->y_pos){	//z and y position of right walls
//		    ball->speed *= -1;
//		   // translate(x_pos, y_pos, z_pos * speed);
//		    ball->z_pos *= ball->speed;
//	}
//	ball->translate(ball->x_pos, ball->y_pos, ball->z_pos);
//	glutPostRedisplay();
//}
void World::resetWorld(){
	board->reset();

	paddleP1->reset();
	paddleP1->translate(-1, 0, 4.5);

	paddleP2->reset();
	paddleP2->translate(-1, 0, -4.5);
//	ball->reset();
}
