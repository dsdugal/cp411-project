#include "Paddle.hpp"

Paddle::Paddle() {
	// mc.loadIdentity();
	// scale = DEFAULT_SCALE;
	speed = DEFAULT_PADDLE_SPEED;
}

Paddle::~Paddle() {}

void Paddle::reset() {
	// mc.loadIdentity();
	// scale = DEFAULT_SCALE;
	speed = DEFAULT_PADDLE_SPEED;
}

GLint Paddle::getSpeed() {
	return speed;
}


void Paddle::setSpeed(GLint s) {
	speed = s;
}




