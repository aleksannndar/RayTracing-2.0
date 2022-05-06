#include "../../include/colliders/BruteForceCollider.h"

BruteForceCollider::BruteForceCollider(std::vector<std::shared_ptr<Body>> bodies) {
	this->bodies = bodies;
}

Collision BruteForceCollider::collide(const Ray& ray) const {
	double minHitT = infinity;
	std::shared_ptr<Hit> minHit = nullptr;
	std::shared_ptr<Body> minHitBody = nullptr;

	for (std::shared_ptr<Body> b : bodies) {
		std::shared_ptr<Hit> h = b->getSolid()->firstHit(ray, epsilon);
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

bool BruteForceCollider::collidesIn01(const Ray& ray) const {
	for (std::shared_ptr<Body> b : bodies) {
		std::shared_ptr<Hit> hit = b->getSolid()->firstHit(ray, epsilon);
		if (hit != nullptr && hit->getT() < 1)
			return true;
	}
	return false;
}