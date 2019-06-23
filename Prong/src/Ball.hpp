#ifndef SRC_BALL_HPP_
#define SRC_BALL_HPP_

#include "Sphere.hpp"
//#include "World.hpp"

const GLfloat DEFAULT_BALL_SPEED = 0.002;

class Ball: public Sphere {
	public:
		GLfloat speed;
		Ball();
		~Ball();
		void reset();
		GLint getSpeed();
		void setSpeed(GLint s);
		void update();
};

#endif
