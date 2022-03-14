#ifndef RAY_H
#define RAY_H

#include "Vec3.h"

class Ray {
private:
	Vec3 origin;
	Vec3 direction;
public:
	Ray();
	Ray(const Vec3& origin, const Vec3& direction);

	Vec3 getOrigin() const;

	Vec3 getDirection() const;

	Vec3 at(double t) const;
};

#endif // !RAY_H

