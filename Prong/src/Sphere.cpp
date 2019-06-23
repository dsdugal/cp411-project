#include "Sphere.hpp"

Sphere::Sphere() {
	radius = 0.25;
	textureID = 0;
	splices = 40; // 50;
	stacks = 40; // 50;
	quad = gluNewQuadric();
}

Sphere::~Sphere() {
	gluDeleteQuadric(quad);
}

void Sphere::draw() {
//	glPushMatrix();
//	this->ctmMultiply();
//	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
//	gluSphere(this->quad, radius, splices, stacks);
//	glPopMatrix();

	gluQuadricTexture(this->quad, GL_TRUE);
	gluQuadricOrientation(this->quad, GLU_OUTSIDE);
	gluQuadricNormals(this->quad, GLU_SMOOTH);

	glPushMatrix();
	ctmMultiply();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, textureID);
	gluSphere(this->quad, radius, 50, 50);
	glPopMatrix();
}

