#ifndef SONAR_H
#define SONAR_H

#include "RayTracer.h"

class Sonar : public RayTracer {
public:
	Sonar(std::shared_ptr<Scene> scene, std::shared_ptr<Collider> collider) : RayTracer(scene, collider) {};

	Vec3 sample(const Ray& ray) const override;
};

#endif
