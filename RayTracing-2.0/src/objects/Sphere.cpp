#include "../../include/objects/Sphere.h"
#include "../../include/objects/hits/HitSphere.h"

Sphere::Sphere(const Vec3& center, double r) {
	this->center = center;
	this->r = r;
	rSqr = r * r;
}

std::shared_ptr<Hit> Sphere::firstHit(const Ray& ray, double afterTime) const {
	Vec3 e = center - ray.getOrigin();

	double dSqr = ray.getDirection().lengthSquared();
	double l = dot(e, ray.getDirection()) / dSqr;
	double mSqr = l * l - (e.lengthSquared() - rSqr) / dSqr;

	if (mSqr > 0) {
		double m = std::sqrt(mSqr);
		if (l - m > afterTime) return std::make_shared<HitSphere>(ray, l - m, *this);
		if (l + m > afterTime) return std::make_shared<HitSphere>(ray, l + m, *this);
	}

	return nullptr;
}

//std::shared_ptr<Hit> Sphere::firstHit(const Ray& ray, double afterTime) const {
//	Vec3 oc = ray.getOrigin() - center;
//	double half_b = dot(ray.getDirection(), oc);
//	double c = oc.lengthSquared() - r * r;
//	double a = ray.getDirection().lengthSquared();
//	double res = half_b * half_b - a * c;
//	if (res < 0) {
//		return nullptr;
//	}
//	double sqrtRes = sqrt(res);
//	double root = (-half_b - sqrtRes) / a;
//	if (root < afterTime) {
//		root = (-half_b + sqrtRes) / a;
//		if (root < afterTime) {
//			return nullptr;
//		}
//	}
//	return std::make_shared<HitSphere>(ray, root, *this);
//}

Vec3 Sphere::getCenter() const {
	return center;
}

double Sphere::getR() const {
	return r;
}

