#include "Ball.hpp"

extern GLint windowHeight;
extern GLint windowWidth;

Ball::Ball() {
	mc.loadIdentity();
	scale = DEFAULT_SCALE;
	speed = DEFAULT_BALL_SPEED;
	x_pos = windowWidth / 2;
	y_pos = windowHeight / 2;
	ball_x_dir = -1.0;
	ball_y_dir = 0;
	size = 50;
}

Ball::~Ball() {}

void Ball::reset() {
	mc.loadIdentity();
	scale = DEFAULT_SCALE;
	speed = DEFAULT_BALL_SPEED;
}

GLint Ball::getSpeed() {
	return speed;
}

void Ball::setSpeed(GLint s) {
	speed = s;
}

void Ball::spawn() {
	glPushMatrix();
	this->ctmMultiply();
	glScalef(1, 1, 1);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
		glVertex2f((x_pos - size)/2, (y_pos - size)/2);
		glVertex2f(x_pos + size, y_pos);
		glVertex2f(x_pos + size, y_pos + size);
		glVertex2f(x_pos, y_pos + size);
	glEnd();
	glPopMatrix();
//	glutPostRedisplay();
}
