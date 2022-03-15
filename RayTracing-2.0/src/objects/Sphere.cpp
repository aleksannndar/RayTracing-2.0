#include "../../include/objects/Sphere.h"

Sphere::Sphere(const Vec3& center, double r) {
	this->center = center;
	this->r = r;
	rSqr = r * r;
}

std::shared_ptr<Hit> Sphere::firstHit(const Ray& r, double afterTime) const {
	Vec3 e = center - r.getOrigin();

	double dSqr = r.getDirection().lengthSquared();
	double l = dot(e, r.getDirection()) / dSqr;
	double mSqr = l * l - (e.lengthSquared() - rSqr) / dSqr;

	if (mSqr > 0) {
		double m = std::sqrt(mSqr);
		if (l - m > afterTime) return std::make_shared<HitData>(l - m, r.at(l - m) - center);
		if (l + m > afterTime) return std::make_shared<HitData>(l + m, r.at(l + m) - center);
	}

	return nullptr;
}

Vec3 Sphere::getCenter() const {
	return center;
}

double Sphere::getR() const {
	return r;
}

