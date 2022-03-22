#include "../../include/utility/Material.h"

Material::Material(const Vec3& diffuse) {
	this->diffuse = diffuse;
}

Vec3 Material::getDiffuse() const{
	return diffuse;
}