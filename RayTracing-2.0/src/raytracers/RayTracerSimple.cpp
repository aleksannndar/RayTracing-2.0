#include "../../include/raytracers/RayTracerSimple.h"


Vec3 RayTracerSimple::sample(const Ray& ray) const {
	Collision collision = this->getCollider()->collide(ray);
	std::shared_ptr<Body> b = collision.getBody();

	return b == nullptr ? getScene()->getBackgroundColor() : b->materialAt(*(collision.getHit())).getDiffuse();
}