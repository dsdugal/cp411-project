#include "Shape3D.hpp"

Shape3D::Shape3D() {
	mc.loadIdentity();
	x_scale = DEFAULT_SCALE;
	y_scale = DEFAULT_SCALE;
	z_scale = DEFAULT_SCALE;
	counter = 0;
	x_pos = mc.mat[0][3];
	y_pos = mc.mat[1][3];
	z_pos = mc.mat[2][3];
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
	x_scale = DEFAULT_SCALE;
	y_scale = DEFAULT_SCALE;
	z_scale = DEFAULT_SCALE;
	counter = 0;
}

void Shape3D::rotate(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) {
	Matrix m;
	m.rotate(rx, ry, rz, angle);
	mc.multiplyMatrix(&m);
}
void Shape3D::rotateMC(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) {
	GLfloat x0 = mc.mat[0][3], y0 = mc.mat[1][3], z0 = mc.mat[2][3];
	translate(-x0, -y0, -z0);
	rotate(rx, ry, rz, angle);
	translate(x0, y0, z0);
	counter++;
	if (counter >= 100){
		mc.normalize();
		counter = 0;
	}
}

void Shape3D::scaleDown(GLfloat decrement) {
	x_scale -= decrement;
	y_scale -= decrement;
	z_scale -= decrement;
}

void Shape3D::scaleUp(GLfloat increment) {
	x_scale += increment;
	y_scale += increment;
	z_scale += increment;
}

void Shape3D::translate(GLfloat x, GLfloat y, GLfloat z) {
	mc.mat[0][3] += x;
	mc.mat[1][3] += y;
	mc.mat[2][3] += z;
	mc.mat[3][3] = 1;

	x_pos = mc.mat[0][3];
	y_pos = mc.mat[1][3];
	z_pos = mc.mat[2][3];
}

void Shape3D::stretch(GLfloat factor){
	x_scale = x_scale * factor;
}
