#include "../../include/utility/Material.h"



Material::Material(const Vec3& diffuse, const Vec3& specular, double shininess) {
	this->diffuse = diffuse;
	this->specular = specular;
	this->shininess = shininess;
}

Vec3 Material::getDiffuse() const{
	return diffuse;
}

Vec3 Material::getSpecular() const {
	return specular;
}

double Material::getShininess() const {
	return shininess;
}

Material Material::setDiffuse(const Vec3& d) {
	return Material(d, this->specular, this->shininess);
}

Material Material::setSpecular(const Vec3& s) {
	return Material(this->diffuse, s, this->shininess);
}

Material Material::setShininess(double s) {
	return Material(this->diffuse, this->specular, s);
}
