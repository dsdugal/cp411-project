#include "Racket.hpp"

extern GLint mode;

Racket::Racket() {
	x_position = 10.0;
	y_position = 50.0;
	width = 10;
	height = 10;
	speed = 3;
}

void Racket::draw() {
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
		glVertex2f(x_position, y_position);
		glVertex2f(x_position + width, y_position);
		glVertex2f(x_position + width, y_position + height);
		glVertex2f(x_position, y_position + height);
	glEnd();
}
