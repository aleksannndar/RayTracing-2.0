#ifndef UNIFORM_H
#define UNIFORM_H

#include "Body.h"


class Uniform : public Body {
private:
	std::shared_ptr<Solid> solid;
	Vec3 material;
public:
	Uniform(const std::shared_ptr<Solid> solid,const Vec3& material);

	std::shared_ptr<Solid> getSolid() const override;
	Vec3 materialAt(const Hit& hit) const override;
};

#endif

