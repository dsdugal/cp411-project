#include "Ball.hpp"
//extern World myWorld;

Ball::Ball() {
	mc.loadIdentity();
	x_scale = DEFAULT_SCALE;
	y_scale = DEFAULT_SCALE;
	z_scale = DEFAULT_SCALE;
	speed = DEFAULT_BALL_SPEED;
}

Ball::~Ball() {}

void Ball::reset() {
	mc.loadIdentity();
	x_scale = DEFAULT_SCALE;
	y_scale = DEFAULT_SCALE;
	z_scale = DEFAULT_SCALE;
	speed = DEFAULT_BALL_SPEED;
}

GLint Ball::getSpeed() {
	return speed;
}

void Ball::setSpeed(GLint s) {
	speed = s;
}

void Ball::update() {
	printf("speed = %f \n", speed);
	x_pos *= speed;
	y_pos *= speed;
	z_pos *= speed;
	printf(" x = %f \n", x_pos);
	printf(" y = %f \n", y_pos);
	printf(" z = %f \n", z_pos);
	if(x_pos <= -7.5 * speed ){	//x position of top middle, top right and top left
		printf("passed top wall \n");
		speed *= -1;
		x_pos *= speed;
		printf("speed after = %f \n", speed);
	}
//	else if(x_pos >= 5.5*speed){	//x position of bottom
//		printf("passed bottom wall \n");
//	    speed *= -1;
//	    //translate(x_pos * speed, y_pos, z_pos);
//	    x_pos *= speed;
//	}
//	else if(z_pos >= 5.35*speed ){	//z and y position of left walls
//		printf("passed left wall \n");
//	    speed *= -1;
//	    //translate(x_pos, y_pos, z_pos * speed);
//	    z_pos *= speed;
//	}
//	else if(z_pos <= -5.35*speed ){	//z and y position of right walls
//		printf("passed right wall \n");
//	    speed *= -1;
//	   // translate(x_pos, y_pos, z_pos * speed);
//	    z_pos *= speed;
//	}
	translate(x_pos, y_pos, z_pos);
	glutPostRedisplay();
}
