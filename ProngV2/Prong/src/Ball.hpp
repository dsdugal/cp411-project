#ifndef SRC_BALL_HPP_
#define SRC_BALL_HPP_

#include "Sphere.hpp"

const GLint DEFAULT_BALL_SPEED = 1;

class Ball: public Sphere {
	protected:
		GLfloat x_pos;
		GLfloat y_pos;
		GLint speed;
		GLfloat ball_x_dir;
		GLfloat ball_y_dir;
		GLfloat size;
	public:
		Ball();
		~Ball();
		void reset();
		GLint getSpeed();
		void setSpeed(GLint s);
		void spawn();
};

#endif
