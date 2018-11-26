#ifndef SRC_VECTOR_HPP_
#define SRC_VECTOR_HPP_

#include <GL/glew.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include "Point.hpp"

//#include <stdio.h>

using namespace std;

class Vector {
	public:
		GLfloat x,y,z;
		Vector();
		Vector(GLfloat dx, GLfloat dy, GLfloat dz);
		void set(GLfloat dx, GLfloat yy, GLfloat dz);
		void set(Vector& v);
		void setDiff(Point& a, Point& b);
		void flip();
		void normalize();
		Vector diff(Point& a, Point& b);
		Vector cross(Vector b);
		GLfloat dot(Vector b);
		void build4tuple(GLfloat v[]);
		void printVector();
};

#endif
