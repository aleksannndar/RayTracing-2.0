#include "../../include/utility/Light.h"

Light::Light(const Vec3& origin, const Vec3& color) {
	this->origin = origin;
	this->color = color;
}

Light::Light(const Vec3& origin) {
	this->origin = origin;
	this->color = Vec3(1.0, 1.0, 1.0);
}

Vec3 Light::getOrigin() const {
	return origin;
}

Vec3 Light::getColor() const {
	return color;
}