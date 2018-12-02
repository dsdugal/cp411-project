#ifndef SRC_PRISM_HPP_
#define SRC_PRISM_HPP_

#include "Shape3D.hpp"

class Prism: public Shape3D {
	protected:
		GLfloat vertex[8][3];
		GLint face[6][4];
	private:
		void drawFace(int faceIndex);
	public:
		GLuint textureID;
		Prism();
		void resizeX(float factor);
		void resizeY(float factor);
		void resizeZ(float factor);
		void draw();
};

#endif
