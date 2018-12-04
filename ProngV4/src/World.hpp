#ifndef SRC_WORLD_HPP_
#define SRC_WORLD_HPP_

#include "Ball.hpp"
#include "Board.hpp"
#include "Paddle.hpp"
#include "Scoreboard.hpp"

class World {
	public:
		Board* board;
		Paddle* paddleP1;
		Paddle* paddleP2;
		Ball* ball;
		World();
		~World();
		void drawWorld();
		//void updateBall();
		void resetWorld();
};

#endif
