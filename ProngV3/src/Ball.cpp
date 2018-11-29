#include "Ball.hpp"

Ball::Ball() {
	mc.loadIdentity();
	x_scale = DEFAULT_SCALE;
	y_scale = DEFAULT_SCALE;
	z_scale = DEFAULT_SCALE;
	speed = DEFAULT_BALL_SPEED;
}

Ball::~Ball() {}

void Ball::reset() {
	mc.loadIdentity();
	x_scale = DEFAULT_SCALE;
	y_scale = DEFAULT_SCALE;
	z_scale = DEFAULT_SCALE;
	speed = DEFAULT_BALL_SPEED;
}

GLint Ball::getSpeed() {
	return speed;
}

void Ball::setSpeed(GLint s) {
	speed = s;
}

void Ball::spawn() {}
