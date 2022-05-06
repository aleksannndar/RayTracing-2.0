#ifndef COLLIDER_H 
#define COLLIDER_H

#include "Collision.h"

class Collider {
public:
	virtual Collision collide(const Ray& ray) const = 0;

	virtual bool collidesIn01(const Ray& ray) const {
		Collision collision = collide(ray);
		return (collision.getBody() != nullptr && collision.getHit()->getT() < 1);
	}
};

#endif 

