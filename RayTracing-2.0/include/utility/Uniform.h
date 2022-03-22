#ifndef UNIFORM_H
#define UNIFORM_H

#include "Body.h"


class Uniform : public Body {
private:
	std::shared_ptr<Solid> solid;
	Material material;
public:
	Uniform(const std::shared_ptr<Solid> solid,const Material& material);

	std::shared_ptr<Solid> getSolid() const override;
	Material materialAt(const Hit& hit) const override;
};

#endif

