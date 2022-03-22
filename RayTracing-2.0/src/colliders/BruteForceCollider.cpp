#include "../../include/colliders/BruteForceCollider.h"

BruteForceCollider::BruteForceCollider(std::vector<std::shared_ptr<Body>> bodies) {
	this->bodies = bodies;
}

Collision BruteForceCollider::collide(const Ray& ray) const {
	double minHitT = infinity;
	std::shared_ptr<Hit> minHit = nullptr;
	std::shared_ptr<Body> minHitBody = nullptr;

	for (std::shared_ptr<Body> b : bodies) {
		std::shared_ptr<Hit> h = b->getSolid()->firstHit(ray, 0.0);
		if (h != nullptr) {
			if (h->getT() < minHitT) {
				minHitT = h->getT();
				minHit = h;
				minHitBody = b;
			}
		}
	}

	return Collision(minHitBody, minHit);
}