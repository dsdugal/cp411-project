#include "Ball.hpp"

extern GLint mode;
extern GLint winWidth;
extern GLint winHeight;

Ball::Ball() {
	x_position = winWidth/2;
	y_position = winHeight/2;
	ball_dir_x = -1.0;
	ball_dir_y = 0.0;
	size = 8;
	speed = 2;
}
//size and size for width and height
void Ball::draw() {
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
		glVertex2f((x_position - size)/2, (y_position - size)/2);
		glVertex2f(x_position + size, y_position);
		glVertex2f(x_position + size, y_position + size);
		glVertex2f(x_position, y_position + size);
	glEnd();
}
