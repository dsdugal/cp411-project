#ifndef SRC_WORLD_HPP_
#define SRC_WORLD_HPP_

#include "Ball.hpp"
#include "Board.hpp"
#include "Paddle.hpp"
#include "Scoreboard.hpp"

const int WORLD_ITEMS = 5; // 1 board, 1 scoreboard, 2 paddles, 1 ball?

class World {
	public:
		Shape3D* items[WORLD_ITEMS];
		World();
		~World();
		void drawWorld();
		void resetWorld();
};

#endif
