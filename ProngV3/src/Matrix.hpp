#ifndef SRC_MATRIX_HPP_
#define SRC_MATRIX_HPP_

#include <GL/glew.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

class Matrix {
	public:
		GLfloat mat[4][4];
		Matrix();
		~Matrix(){};
		void loadIdentity();
		void multiplyMatrix(Matrix* m);
		void multiplyVector(GLfloat* v);
		void normalize();
		void rotate(GLfloat x, GLfloat y, GLfloat z, GLfloat angle);
		void transpose();

};

#endif
