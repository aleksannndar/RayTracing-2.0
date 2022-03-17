#include "../../include/objects/HalfSpace.h"

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
	this->p = p;
	this->n = n;

	double nl = n.length();
	e = normal(n) / nl;
	f = cross(e, n) / nl;

	HalfSpace(p, e ,f);
}

std::shared_ptr<Hit> HalfSpace::firstHit(const Ray& r, double afterTime) const{
	return nullptr;
}