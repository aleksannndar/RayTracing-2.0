#ifndef HIT_SPHERE_H
#define HIT_SPHERE_H

#include "Hit.h"
#include "Sphere.h"

class HitSphere : public Hit {
private:
	Ray ray;
	double t;
	Sphere sphere;
public:
	HitSphere(const Ray& ray, double t,const Sphere& sphere);

	double getT() const override;

	Ray getRay() const override;

	Vec3 getN() const override;

	Vec3 n_() const;
};

#endif 

