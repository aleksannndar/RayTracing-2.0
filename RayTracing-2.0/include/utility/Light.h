#ifndef LIGHT_H
#define LIGHT_H

#include "MainHeader.h"

class Light {
private:
	Vec3 origin;
	Vec3 color;

public:
	Light(const Vec3& origin, const Vec3& color);

	Vec3 getOrigin() const;

	Vec3 getColor() const;
};

#endif 

