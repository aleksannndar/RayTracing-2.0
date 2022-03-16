#include "../../include/objects/HitSphere.h"

HitSphere::HitSphere(const Ray& ray, double t, const Sphere& sphere) {
	this->ray = ray;
	this->t = t;
	this->sphere = sphere;
}

double HitSphere::getT() const {
	return t;
}

Ray HitSphere::getRay() const {
	return ray;
}

Vec3 HitSphere::getN() const {
	return ray.at(t) - sphere.getCenter();
}

Vec3 HitSphere::n_() const {
	return this->getN() / sphere.getR();
}