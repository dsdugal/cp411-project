#ifndef SRC_RACKET_H
#define SRC_RACKET_H

#include <GL/glut.h>

class Racket {
public:
	GLfloat x_position;
	GLfloat y_position;
	GLint width;
	GLint height;
	GLint speed;

	Racket();
	void draw();


private:
//	void draw_face(int);
};

#endif
