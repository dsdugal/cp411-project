#ifndef SRC_BALL_H
#define SRC_BALL_H

#include <GL/glut.h>

class Ball {
public:
	GLfloat x_position;
	GLfloat y_position;
	GLfloat ball_dir_x;
	GLfloat ball_dir_y;
	GLint size;
	GLint speed;

	Ball();
	void draw();


private:
//	void draw_face(int);
};

#endif
