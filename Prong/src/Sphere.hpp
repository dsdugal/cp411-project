#ifndef SRC_SPHERE_HPP_
#define SRC_SPHERE_HPP_

#include "Shape3D.hpp"

class Sphere: public Shape3D {
	public:
		GLfloat radius;
		GLint splices, stacks;
		GLuint textureID;
		GLUquadric *quad;
		Sphere();
		~Sphere();
		void draw();
};

#endif
