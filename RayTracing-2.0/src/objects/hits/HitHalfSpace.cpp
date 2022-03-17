#include "../../../include/objects/hits/HitHalfSpace.h"

HitHalfSpace::HitHalfSpace(const Ray& ray, double t, const HalfSpace& hs) {
	this->ray = ray;
	this->t = t;
	this->hs = hs;
}

double HitHalfSpace::getT() const {
	return t;
}

Ray HitHalfSpace::getRay() const {
	return ray;
}

Vec3 HitHalfSpace::getN() const {
	return hs.getN();
}

Vec3 HitHalfSpace::n_() const {
	return hs.getN_();
}