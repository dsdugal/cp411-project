#ifndef SRC_CAMERA_HPP_
#define SRC_CAMERA_HPP_

#include "Camera.hpp"
#include "Matrix.hpp"
#include "Point.hpp"
#include "Vector.hpp"

class Camera {
	public:
		GLfloat aspect, dnear, dfar, vangle, W, H;
		Point eye;
		Point ref;
		Vector viewNorm;
		Vector viewUp;
		Camera();
		void set(Point Eye, Point look, Vector up);
		void set(float ex, float ey, float ez, float lx, float ly, float lz, float upx, float upy, float upz);
		void setRef(float lx, float ly, float lz);
		void setViewNorm();
		void printCamera(void);
		void setDefaultCamera();
		void rotate(GLfloat rx, GLfloat rz, GLfloat ry, GLfloat angle);
		void translate(GLfloat tx, GLfloat ty, GLfloat tz);
		void setViewVolume(float viewAngle, float aspect, float Near, float Far);
		void setAspect(float aspect);
		void setProjectionMatrix();
};

#endif
