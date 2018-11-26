#include "Paddle.hpp"

Paddle::Paddle() {
	// mc.loadIdentity();
	// scale = DEFAULT_SCALE;
	speed = DEFAULT_PADDLE_SPEED;
	x_pos = 10;
	y_pos = 50;
	width = 15;
	height = 15;
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

void Paddle::draw(){
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
		glVertex2f(x_pos, y_pos);
		glVertex2f(x_pos + width, y_pos);
		glVertex2f(x_pos + width, y_pos + height);
		glVertex2f(x_pos, y_pos + height);
	glEnd();
}




