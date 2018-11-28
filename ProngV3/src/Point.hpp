#ifndef SRC_POINT_HPP_
#define SRC_POINT_HPP_

#include <GL/glew.h>
#include <GL/glut.h>

class Point {
	public:
		GLfloat x,y,z;
		Point();
		void reset();
		void set(GLfloat x, GLfloat y, GLfloat z);
		void set(Point p);
		void normalize();
		void crossProduct(Point, Point);
		Point getNormal(Point, Point);
};

#endif
