#include "../../include/objects/HalfSpace.h"
#include "../../include/objects/hits/HitHalfSpace.h"

HalfSpace::HalfSpace(const Vec3& p, const Vec3& e, const Vec3& f) {
	this->p = p;
	this->e = e;
	this->f = f;

	n = cross(e, f);
	n_ = n / n.length();

	eLSqr = e.lengthSquared();
	fLSqr = f.lengthSquared();
	double ef = dot(e, f);
	e_f = ef / fLSqr;
	f_e = ef / eLSqr;
	sinSqr = 1 - e_f * f_e;
}

HalfSpace::HalfSpace(const Vec3& p, const Vec3& n) {
	double nl = n.length();
	Vec3 e = normal(n) / nl;
	Vec3 f = cross(n, e) / nl;
	this->HalfSpace::HalfSpace(p, e, f);
}

Vec3 HalfSpace::getP() const {
	return p;
}

Vec3 HalfSpace::getE() const {
	return e;
}

Vec3 HalfSpace::getF() const {
	return f;
}

Vec3 HalfSpace::getN() const {
	return n;
}

Vec3 HalfSpace::getN_() const {
	return n_;
}

std::shared_ptr<Hit> HalfSpace::firstHit(const Ray& ray, double afterTime) const{
	double o = dot(n, ray.getDirection());

	if (o == 0) {
		return nullptr;
	}
	else {
		double t = dot(n,p - ray.getOrigin()) / o;
		if (t > afterTime) {
			return std::make_shared<HitHalfSpace>(ray, t, *this);
		}
		else {
			return nullptr;
		}
	}
	return nullptr;
}