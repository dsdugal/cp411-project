#include "World.hpp"

World::World() {
	board = new Board();
	scoreboard = new Scoreboard();
	paddleP1 = new Paddle();
	paddleP1->scaleDown(0.9);
	paddleP1->translate(-1, 0, 5);
	paddleP2 = new Paddle();
	paddleP2->scaleDown(0.9);
	paddleP2->translate(-1, 0, -5);
	ball = new Ball();
	ball->translate(-1, 0, 0);
}

World::~World(){
	delete board;
	delete scoreboard;
	delete paddleP1;
	delete paddleP2;
	delete ball;
}

void World::drawWorld() {
	board->drawBoard();	//call to drawBoard instead of draw
	scoreboard->draw();
	paddleP1->draw();
	paddleP2->draw();
	ball->draw();
}

void World::resetWorld(){
	board->reset();
	scoreboard->reset();
	paddleP1->reset();
	paddleP2->reset();
	ball->reset();
}
