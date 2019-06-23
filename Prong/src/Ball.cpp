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
	translate(x_pos * speed, y_pos * speed, z_pos * speed);
	speed += 0.000003;	//dont know why?
	if(x_pos < -7.5){	//x position of top middle, top right and top left
		printf("passed top wall \n");
		printf("x = %f \n", x_pos);
		x_pos *= -1;
		printf("x = %f \n", x_pos);
	}
	else if(x_pos >= 5.5){	//x position of bottom
		printf("passed bottom wall \n");
	    //translate(x_pos * speed, y_pos, z_pos);
	    x_pos *= -1;
	}

	if(z_pos >= 5.35 ){	//z and y position of left walls
		printf("passed left wall \n");
	    //translate(x_pos, y_pos, z_pos * speed);
	    z_pos *= -1;
	}
	else if(z_pos <= -5.35 ){	//z and y position of right walls
		printf("passed right wall \n");
	   // translate(x_pos, y_pos, z_pos * speed);
	    z_pos *= -1;
	}
	glutPostRedisplay();
}
