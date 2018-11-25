#ifndef SRC_BALL_HPP_
#define SRC_BALL_HPP_

#include "Sphere.hpp"

const GLint DEFAULT_BALL_SPEED = 1;

class Ball: Sphere {
	protected:
		GLint speed;
	public:
		Ball();
		~Ball();
		void reset();
		GLint getSpeed();
		void setSpeed(GLint s);
		void spawn();
};

#endif
