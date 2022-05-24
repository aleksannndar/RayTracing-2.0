#ifndef RAY_TRACER_SIMPLE_H
#define RAY_TRACER_SIMPLE_H

#include "RayTracer.h"

class RayTracerSimple : public RayTracer {
	int maxDepth;
public:
	RayTracerSimple(std::shared_ptr<Scene> scene, std::shared_ptr<Collider> collider, int maxDepth) : RayTracer(scene, collider) {
		this->maxDepth = maxDepth;
	};

	Vec3 sample(const Ray& ray) const override;

	Vec3 sample(const Ray& ray, int depthRemaining) const;
};

#endif