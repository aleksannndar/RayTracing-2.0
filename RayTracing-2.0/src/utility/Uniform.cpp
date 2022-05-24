#include "../../include/utility/Uniform.h"

Uniform::Uniform(const std::shared_ptr<Solid> solid, const Material& material) {
	this->solid = solid;
	this->material = material;
}

Uniform::Uniform(const std::shared_ptr<Solid> solid) {
	this->solid = solid;
	this->material = defaultMaterial;
}

std::shared_ptr<Solid> Uniform::getSolid() const {
	return solid;
}

Material Uniform::materialAt(const Hit& hit) const {
	return material;
}