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
		GLfloat scale;
	public:
		Shape3D();
		virtual ~Shape3D();
		virtual void draw();
		Matrix getMC();
		void reset();
		void rotate(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle);
		void scaleDown(GLfloat decrement);
		void scaleUp(GLfloat increment);
		void translate(GLfloat x, GLfloat y, GLfloat z);
		void ctmMultiply();
};

#endif
