#ifndef SOLID_H
#define SOLID_H

#include "Ray.h"
#include "../objects/hits/Hit.h"
#include <memory>

class Solid {
public:
	virtual std::shared_ptr<Hit> firstHit(const Ray& r, double afterTime) const = 0;
};

#endif 
