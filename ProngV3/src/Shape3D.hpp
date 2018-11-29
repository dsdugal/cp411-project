#ifndef SRC_SHAPE3D_HPP_
#define SRC_SHAPE3D_HPP_

#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include "Matrix.hpp"

const GLfloat DEFAULT_SCALE = 1;

class Shape3D {
	protected:
		Matrix mc;
		GLfloat x_scale;
		GLfloat y_scale;
		GLfloat z_scale;
		GLint counter;
	public:
		GLint x_pos;
		GLint y_pos;
		GLint z_pos;
		Shape3D();
		virtual ~Shape3D();
		virtual void draw();
		Matrix getMC();
		void ctmMultiply();
		void reset();
		void rotate(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);
		void rotateMC(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);
		void scaleDown(GLfloat decrement);
		void scaleUp(GLfloat increment);
		void translate(GLfloat x, GLfloat y, GLfloat z);
		void stretch(GLfloat factor);	//implement this stretch function
};

#endif
