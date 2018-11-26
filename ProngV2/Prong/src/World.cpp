#include "World.hpp"
#include <stdio.h>
#include <stdlib.h>

World::World() {
	board = new Board();
	scoreboard = new Scoreboard();
	paddleP1 = new Paddle();
	paddleP2 = new Paddle();
	ball = new Ball();
}

World::~World(){
	delete board;
	delete scoreboard;
	delete paddleP1;
	delete paddleP2;
	delete ball;
}

void World::drawWorld() {
	board->draw();
	scoreboard->draw();
	paddleP1->draw();
	paddleP2->draw();
	ball->spawn();
	printf("penis \n");
}

void World::resetWorld(){
	board->reset();
	scoreboard->reset();
	paddleP1->reset();
	paddleP2->reset();
	ball->reset();
}
