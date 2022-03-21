#ifndef BRUTE_FORCE_COLLIDER_H
#define BRUTE_FORCE_COLLIDER_H

#include <memory>
#include <vector>

#include "Collider.h"

class BruteForceCollider : public Collider {
private:
	std::vector<std::shared_ptr<Body>> bodies;
public:
	BruteForceCollider(std::vector<std::shared_ptr<Body>> bodies);

	Collision collide(const Ray& ray) const override;
};

#endif 

