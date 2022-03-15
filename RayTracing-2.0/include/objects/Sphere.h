#ifndef SPHERE_H
#define SPHERE_H

#include "../utility/Solid.h"

class Sphere : public Solid {
private:
	Vec3 center;
	double r;
	double rSqr;
public:
	Sphere(const Vec3& origin, double r);

	std::shared_ptr<Hit> firstHit(const Ray& r, double afterTime) const override;

	Vec3 getCenter() const;

	double getR() const;
};

#endif // !SPHERE_H

