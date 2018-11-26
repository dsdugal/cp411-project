#ifndef SRC_PADDLE_HPP_
#define SRC_PADDLE_HPP_

#include "Prism.hpp"

const GLint DEFAULT_PADDLE_SPEED = 1;

class Paddle: public Prism {
	protected:
		GLint speed;
		GLfloat x_pos;
		GLfloat y_pos;
		GLfloat width;
		GLfloat height;
	public:
		Paddle();
		~Paddle();
		void reset();
		GLint getSpeed();
		void setSpeed(GLint s);
		void draw();
};

#endif
