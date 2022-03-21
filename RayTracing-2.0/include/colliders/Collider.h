#ifndef COLLIDER_H 
#define COLLIDER_H

#include "Collision.h"

class Collider {
public:
	virtual Collision collide(const Ray& ray) const = 0;
};

#endif 

