#ifndef HALF_SPACE_H
#define HALF_SPACE_H

#include "../utility/Solid.h"

class HalfSpace : public Solid {
private:
	Vec3 p; //point on the boundary plane
	Vec3 e; //vector parallel to the boundary plane
	Vec3 f; //vector parallel to the boundary plane, not parallel to e

	Vec3 n; //normal vector to the boundary plane
	Vec3 n_; //normal vector to the boundary plane, normalized

	double e_f, f_e, eLSqr, fLSqr, sinSqr;
public:

	HalfSpace() {};

	HalfSpace(const Vec3& p, const Vec3& e, const Vec3& f);

	HalfSpace(const Vec3& p, const Vec3& n);

	Vec3 getP() const;

	Vec3 getE() const;
	
	Vec3 getF() const;

	Vec3 getN() const;

	Vec3 getN_() const;

	std::shared_ptr<Hit> firstHit(const Ray& r, double afterTime) const override;
};

#endif

