#include "Sphere.hpp"

Sphere::Sphere() {
	radius = 1.0;
	textureID = 0;
	splices = 50;
	stacks = 50;
	quad = gluNewQuadric();
}

Sphere::~Sphere() {
	gluDeleteQuadric(quad);
}

void Sphere::draw() {
	glPushMatrix();
	this->ctmMultiply();
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	gluSphere(this->quad, radius, splices, stacks);
	glPopMatrix();
}

