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
	// ball->draw();
}

void World::resetWorld(){
	board->reset();
	paddleP1->reset();
	paddleP2->reset();
	ball->reset();
}
