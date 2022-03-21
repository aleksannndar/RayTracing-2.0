#ifndef RAY_TRACER_H
#define RAY_TRACER_H

#include <memory>

#include "../colliders/Collider.h"
#include "../scenes/Scene.h"

class RayTracer {
private:
	std::shared_ptr<Scene> scene;
	std::shared_ptr<Collider> collider;
public:
	RayTracer(std::shared_ptr<Scene> scene, std::shared_ptr<Collider> collider);

	std::shared_ptr<Scene> getScene() const;

	std::shared_ptr<Collider> getCollider() const;

	virtual Vec3 sample(const Ray& ray) const = 0;

};

#endif

