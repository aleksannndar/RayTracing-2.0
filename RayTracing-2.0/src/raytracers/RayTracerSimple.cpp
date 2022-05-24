#include "../../include/raytracers/RayTracerSimple.h"
#include "../../include/utility/Light.h"

Vec3 RayTracerSimple::sample(const Ray& ray) const {
	return sample(ray, maxDepth);
}

Vec3 RayTracerSimple::sample(const Ray& ray, int depthRemaining) const {
	if (depthRemaining == 0)
		return Vec3(0.0, 0.0, 0.0);

	Collision collision = this->getCollider()->collide(ray);
	std::shared_ptr<Body> body = collision.getBody();
	std::shared_ptr<Hit> hit = collision.getHit();

	if (hit == nullptr)
		return getScene()->getBackgroundColor();

	Material material = body->materialAt(*hit);

	Vec3 n_ = hit->n_();
	Vec3 p = ray.at(hit->getT());
	//Vector from hit point to origin of ray
	Vec3 pToO = ray.getOrigin() - p;
	//Reflected pToO
	Vec3 pToOReflected = reflectedN(pToO, n_);
	double pToOLength = pToO.length();


	Vec3 lightDiffuse = Vec3(0.0,0.0,0.0);
	Vec3 lightSpecular = Vec3(0.0, 0.0, 0.0);

	for (std::shared_ptr<Light> light : this->getScene()->getLights()) {
		//Vector from hit point to origin of light
		Vec3 l = light->getOrigin() - p;

		//Ray from hit to light
		Ray rayToLight = Ray(p, l);
		//std::shared_ptr<Hit> hitLight = this->getCollider()->collide(rayToLight).getHit();

		if (!this->getCollider()->collidesIn01(rayToLight)) {
			double lLengthSqr = l.lengthSquared();
			double lLength = std::sqrt(lLengthSqr);
			double cosNL = dot(n_, l) / lLength;

			if (cosNL > 0) {
				Vec3 irradiance = light->getColor() * (cosNL / lLengthSqr);
				lightDiffuse += irradiance;

				//Check if angle between L and I is acute
				double li = dot(l, pToOReflected);

				if (li > 0) {
					double cosLI = li / (lLength * pToOLength);
					lightSpecular += irradiance * std::pow(cosLI, material.getShininess());
				}
			}

		}
	}

	Vec3 result = Vec3(0.0, 0.0, 0.0);
	result += (body->materialAt(*hit).getDiffuse() * lightDiffuse);
	result += (body->materialAt(*hit).getSpecular() * lightSpecular);

	if (body->materialAt(*hit).getReflective().notZero()) {
		result += sample(Ray(p, pToOReflected), depthRemaining - 1) * body->materialAt(*hit).getReflective();
	}

	if (body->materialAt(*hit).getRefractive().notZero()) {
		double ri = body->materialAt(*hit).getRefractiveIndex();
		double c1 = dot(pToO, n_) / pToOLength;

		double k = 1;
		if (c1 < 0) {
			ri = 1 / ri;
			k = -1;
		}

		double s1Sqr = 1 - c1 * c1;
		double s2Sqr = s1Sqr / (ri * ri);
		double c2Sqr = 1 - s2Sqr;

		Vec3 f;
		if (c2Sqr >= 0) {
			double c2 = k * std::sqrt(c2Sqr);
			f = (n_ * (c1 / ri - c2)) - (pToO / (ri * pToOLength));
		}
		else {
			f = pToOReflected;
		}

		result += (sample(Ray(p, f), depthRemaining - 1) * body->materialAt(*hit).getRefractive());

	}

	return result;
}