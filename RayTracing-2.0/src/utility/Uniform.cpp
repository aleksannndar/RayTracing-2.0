#include "../../include/utility/Uniform.h"

Uniform::Uniform(const std::shared_ptr<Solid> solid, const Vec3& material) {
	this->solid = solid;
	this->material = material;
}

std::shared_ptr<Solid> Uniform::getSolid() const {
	return solid;
}

Vec3 Uniform::materialAt(const Hit& hit) const {
	return material;
}