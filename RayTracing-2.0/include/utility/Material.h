#ifndef MATERIAL_H
#define MATERIAL_H

#include "MainHeader.h"

class Material {
private:
	Vec3 diffuse;
	Vec3 specular;
	double shininess;
	Vec3 reflective;
	Vec3 refractive;
	double refractiveIndex;
public:
	Material() {};
	Material(const Vec3& diffuse, const Vec3& specular, double shininess, const Vec3& reflective, const Vec3& refractive, double refractiveIndex);

	Vec3 getDiffuse() const;

	Vec3 getSpecular() const;

	double getShininess() const;

	Vec3 getReflective() const;

	double getRefractiveIndex() const;

	Vec3 getRefractive() const;

	Material setDiffuse(const Vec3& d);

	Material setSpecular(const Vec3& s);

	Material setShininess(double s);

	Material setReflective(const Vec3& r);

	Material setRefractiveIndex(double r);

	Material setRefractive(const Vec3& r);
};

static Material defaultMaterial = Material(Vec3(1.0, 1.0, 1.0), Vec3(0.0, 0.0, 0.0), 0.0, Vec3(0.0,0.0,0.0), Vec3(0.0,0.0,0.0), 1.4);

#endif // !MATERIAL_H
