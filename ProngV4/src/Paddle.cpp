#include "Paddle.hpp"

Paddle::Paddle() {
	// mc.loadIdentity();
	// scale = DEFAULT_SCALE;
	speed = DEFAULT_PADDLE_SPEED;
}

Paddle::~Paddle() {}

void Paddle::reset() {
	mc.loadIdentity();
	// scale = DEFAULT_SCALE;
	speed = DEFAULT_PADDLE_SPEED;
	x_pos = mc.mat[0][3];
	y_pos = mc.mat[1][3];
	z_pos = mc.mat[2][3];
}

GLint Paddle::getSpeed() {
	return speed;
}

void Paddle::setSpeed(GLint s) {
	speed = s;
}




