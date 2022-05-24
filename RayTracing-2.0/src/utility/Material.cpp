#include "../../include/utility/Material.h"



Material::Material(const Vec3& diffuse, const Vec3& specular, double shininess, const Vec3& reflective, const Vec3& refractive, double refractiveIndex) {
	this->diffuse = diffuse;
	this->specular = specular;
	this->shininess = shininess;
	this->reflective = reflective;
	this->refractive = refractive;
	this->refractiveIndex = refractiveIndex;
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

double Material::getRefractiveIndex() const {
	return refractiveIndex;
}

Vec3 Material::getRefractive() const {
	return refractive;
}

Material Material::setDiffuse(const Vec3& d) {
	return Material(d, this->specular, this->shininess, this->reflective, this->refractive, this->refractiveIndex);
}

Material Material::setSpecular(const Vec3& s) {
	return Material(this->diffuse, s, this->shininess, this->reflective, this->refractive, this->refractiveIndex);
}

Material Material::setShininess(double s) {
	return Material(this->diffuse, this->specular, s, this->reflective, this->refractive, this->refractiveIndex);
}

Material Material::setReflective(const Vec3& r) {
	return Material(this->diffuse, this->specular, this->shininess, r, this->refractive, this->refractiveIndex);
}

Material Material::setRefractive(const Vec3& r) {
	return Material(this->diffuse, this->specular, this->shininess, this->reflective, r, this->refractiveIndex);
}


Material Material::setRefractiveIndex(double r) {
	return Material(this->diffuse, this->specular, this->shininess, this->reflective, this->refractive, r);
}
