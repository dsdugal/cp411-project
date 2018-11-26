#include "Shape3D.hpp"

Shape3D::Shape3D() {
	mc.loadIdentity();
	scale = DEFAULT_SCALE;
}

Shape3D::~Shape3D() {}

Matrix Shape3D::getMC() {
	return mc;
}

void Shape3D::ctmMultiply() {
	mc.transpose();
	glMultMatrixf(&mc.mat[0][0]);
	mc.transpose();
}

void Shape3D::draw() {}

void Shape3D::reset() {
	mc.loadIdentity();
	scale = DEFAULT_SCALE;
}

void Shape3D::rotate(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) {
	Matrix m;
	m.rotate(rx, ry, rz, angle);
	mc.multiplyMatrix(&m);
}

void Shape3D::scaleDown(GLfloat decrement) {
	scale -= decrement;
}

void Shape3D::scaleUp(GLfloat increment) {
	scale += increment;
}

void Shape3D::translate(GLfloat x, GLfloat y, GLfloat z) {
	mc.mat[0][3] += x;
	mc.mat[1][3] += y;
	mc.mat[2][3] += z;
	mc.mat[3][3] = 1;
}
