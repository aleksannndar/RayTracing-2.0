#include "../../include/raytracers/Sonar.h"

Vec3 Sonar::sample(const Ray& ray) const {
	Collision collision = this->getCollider()->collide(ray);

	std::shared_ptr<Hit> hit = collision.getHit();

	if (hit == nullptr) {
		return Vec3(0.0, 0.0, 0.0);
	}
	else {
		double gray = 1.0 / (1.0 + hit->getT());
		return Vec3(gray,gray,gray);
	}
}