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
	glPushMatrix();
	this->ctmMultiply();
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	gluSphere(this->quad, radius, splices, stacks);
	glPopMatrix();
}

