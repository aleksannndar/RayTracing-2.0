#ifndef HIT_HALF_SPACE_H
#define HIT_HALF_SPACE_H

#include "Hit.h"
#include "../HalfSpace.h"

class HitHalfSpace : public Hit {
private:
	Ray ray;
	double t;
	HalfSpace hs;
public:
	HitHalfSpace(const Ray& ray, double t, const HalfSpace& hs);

	double getT() const override;

	Ray getRay() const override;

	Vec3 getN() const override;

	Vec3 n_() const;
};

#endif

