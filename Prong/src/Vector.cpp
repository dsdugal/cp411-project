#include "Vector.hpp"

Vector::Vector() {
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

Vector::Vector(GLfloat dx, GLfloat dy, GLfloat dz) {
	x = dx;
	y = dy;
	z = dz;
}

void Vector::set(GLfloat dx, GLfloat dy, GLfloat dz) {
	x = dx;
	y = dy;
	z = dz;
}

void Vector::set(Vector& v) {
	x = v.x;
	y = v.y;
	z = v.z;
}

Vector Vector::cross(Vector b) {
	Vector c(y*b.z - z*b.y, z*b.x - x*b.z, x*b.y - y*b.x);
	return c;
}

GLfloat Vector::dot(Vector b) {
	return (x * b.x + y * b.y + z * b.z);
}

void Vector::build4tuple(float v[]) {
	v[0] = x; v[1] = y; v[2] = z; v[3] = 0.0f;
}

void Vector::normalize() {
	GLdouble sqs = x * x + y * y + z * z;
	if (sqs < 0.0000001) {
		std::cerr << "\nnormalize() sees vector (0,0,0)!";
		return;
	}
	GLfloat scaleFactor = 1.0/(GLfloat)sqrt(sqs);
	x *= scaleFactor;
	y *= scaleFactor;
	z *= scaleFactor;
}

void Vector::setDiff(Point& a, Point& b) {
	x = a.x - b.x;
	y = a.y - b.y;
	z = a.z - b.z;
}

void Vector::flip() {
	x = -x;
	y = -y;
	z = -z;
}
