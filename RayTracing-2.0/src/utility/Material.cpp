#include "../../include/utility/Material.h"



Material::Material(const Vec3& diffuse, const Vec3& specular, double shininess, const Vec3& reflective) {
	this->diffuse = diffuse;
	this->specular = specular;
	this->shininess = shininess;
	this->reflective = reflective;
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

Vec3 Material::getReflective() const {
	return reflective;
}

Material Material::setDiffuse(const Vec3& d) {
	return Material(d, this->specular, this->shininess, this->reflective);
}

Material Material::setSpecular(const Vec3& s) {
	return Material(this->diffuse, s, this->shininess, this->reflective);
}

Material Material::setShininess(double s) {
	return Material(this->diffuse, this->specular, s, this->reflective);
}

Material Material::setReflective(const Vec3& r) {
	return Material(this->diffuse, this->specular, this->shininess, r);
}
