#ifndef RAY_TRACER_SIMPLE_H
#define RAY_TRACER_SIMPLE_H

#include "RayTracer.h"

class RayTracerSimple : public RayTracer {
public:
	RayTracerSimple(std::shared_ptr<Scene> scene, std::shared_ptr<Collider> collider) : RayTracer(scene, collider) {};

	Vec3 sample(const Ray& ray) const override;
};

#endif