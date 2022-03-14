#include "../../include/utility/Ray.h"

Ray::Ray() {
	origin = Vec3();
	direction = Vec3();
}

Ray::Ray(const Vec3& origin, const Vec3& direction) {
	this->origin = origin;
	this->direction = direction;
}

Vec3 Ray::getOrigin() const {
	return origin;
}

Vec3 Ray::getDirection() const {
	return direction;
}

Vec3 Ray::at(double t) const {
	return origin + t * direction;
}
