#include "../../include/raytracers/RayTracerSimple.h"
#include "../../include/utility/Light.h"


Vec3 RayTracerSimple::sample(const Ray& ray) const {
	Collision collision = this->getCollider()->collide(ray);
	std::shared_ptr<Body> body = collision.getBody();
	std::shared_ptr<Hit> hit = collision.getHit();

	if (hit == nullptr)
		return getScene()->getBackgroundColor();

	Vec3 n_ = hit->n_();
	Vec3 p = ray.at(hit->getT());

	Vec3 lightDiffuse = Vec3(0.0,0.0,0.0);
	for (std::shared_ptr<Light> light : this->getScene()->getLights()) {
		Vec3 l = light->getOrigin() - p;

		Ray rayToLight = Ray(p, l);
		std::shared_ptr<Hit> hitLight = this->getCollider()->collide(rayToLight).getHit();

		if (hitLight == nullptr || hitLight->getT() > 1) {
			double lLengthSqr = l.lengthSquared();
			double lLength = std::sqrt(lLengthSqr);
			double cosNL = dot(n_, l) / lLength;

			if (cosNL > 0)
				lightDiffuse += light->getColor() * (cosNL / lLengthSqr);
		}
	}

	return body->materialAt(*hit).getDiffuse() * lightDiffuse;
}