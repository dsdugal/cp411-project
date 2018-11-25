#include "World.hpp"

World::World() {
	items[0] = new Board();
	items[1] = new Scoreboard();
	items[2] = new Paddle();
	items[3] = new Paddle();
	items[4] = new Ball();
}

World::~World(){
	int i;
	for (i = 0; i < WORLD_ITEMS; i++) {
		delete items[i];
	}
}

void World::drawWorld() {
	int i;
	for (i = 0; i < WORLD_ITEMS; i++) {
		items[i]->draw();
	}
}

void World::resetWorld(){
	int i;
	for (i = 0; i < WORLD_ITEMS; i++) {
		items[i]->reset();
	}
}
