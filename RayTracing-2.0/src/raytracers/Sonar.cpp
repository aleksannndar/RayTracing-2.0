#include "../../include/raytracers/Sonar.h"

Vec3 Sonar::sample(const Ray& ray) const {
	Collision collision = this->getCollider()->collide(ray);

	std::shared_ptr<Hit> hit = collision.getHit();

	if (hit == nullptr) {
		return this->getScene()->getBackgroundColor();
	}
	else {
		double gray = 1.0 / (1.0 + hit->getT());
		return Vec3(gray,gray,gray);
	}
}