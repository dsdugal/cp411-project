#ifndef SRC_PADDLE_HPP_
#define SRC_PADDLE_HPP_

#include "Prism.hpp"

const GLint DEFAULT_PADDLE_SPEED = 1;

class Paddle: public Prism {
	protected:
		GLint speed;
	public:
		Paddle();
		~Paddle();
		void reset();
		GLint getSpeed();
		void setSpeed(GLint s);
};

#endif
