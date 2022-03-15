#include "../../include/utility/Camera.h"

Camera::Camera(const Vec3& origin, const Vec3& lookAt, double aspectRatio, double vfov) {
	this->origin = origin;
	double theta = vfov / 2.0;
	double h = std::tan(theta);
	double heightViewport = 2.0 * h;
	double widthViewport = aspectRatio * heightViewport;

	w = unitVector(origin - lookAt);
	u = cross(w, Vec3(0.0,1.0,0.0));
	v = cross(u,w);

	vertical = v * heightViewport;
	horizontal = u * widthViewport;

	lowerLeftCorner = origin - vertical / 2.0 - horizontal / 2.0 - w;
}

Ray Camera::getRay(double i, double j) const{
	return Ray(origin, lowerLeftCorner + i*vertical + j*horizontal - origin);
}