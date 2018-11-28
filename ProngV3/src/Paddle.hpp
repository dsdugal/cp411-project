#ifndef SRC_PADDLE_HPP_
#define SRC_PADDLE_HPP_

#include "Prism.hpp"

const GLint DEFAULT_PADDLE_SPEED = 1;

class Paddle: public Prism {
	protected:
		GLint speed;
	public:
//		GLint x_pos;
//		GLint y_pos;
//		GLint z_pos;
		Paddle();
		~Paddle();
		void reset();
		GLint getSpeed();
		void setSpeed(GLint s);
};

#endif
