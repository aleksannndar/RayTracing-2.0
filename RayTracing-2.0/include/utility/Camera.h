#ifndef CAMERA_H
#define CAMERA_H

#include "MainHeader.h"

class Camera {
private:
	Vec3 origin;
	Vec3 vertical;
	Vec3 horizontal;
	Vec3 lowerLeftCorner;
	Vec3 u;
	Vec3 v;
	Vec3 w;
public:
	Camera(const Vec3& origin, const Vec3& lookAt,double aspectRatio, double vfov);

	Ray getRay(double i, double j) const;
};

#endif

