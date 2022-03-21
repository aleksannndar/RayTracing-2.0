#include "../../include/raytracers/RayTracer.h"

RayTracer::RayTracer(std::shared_ptr<Scene> scene, std::shared_ptr<Collider> collider) {
	this->scene = scene;
	this->collider = collider;
}

std::shared_ptr<Scene> RayTracer::getScene() const{
	return scene;
}

std::shared_ptr<Collider> RayTracer::getCollider() const {
	return collider;
}
