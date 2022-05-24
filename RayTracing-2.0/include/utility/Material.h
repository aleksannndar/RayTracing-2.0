#ifndef MATERIAL_H
#define MATERIAL_H

#include "MainHeader.h"

class Material {
private:
	Vec3 diffuse;
	Vec3 specular;
	double shininess;
	Vec3 reflective;
public:
	Material() {};
	Material(const Vec3& diffuse, const Vec3& specular, double shininess, const Vec3& reflective);

	Vec3 getDiffuse() const;

	Vec3 getSpecular() const;

	double getShininess() const;

	Vec3 getReflective() const;

	Material setDiffuse(const Vec3& d);

	Material setSpecular(const Vec3& s);

	Material setShininess(double s);

	Material setReflective(const Vec3& r);
};

static Material defaultMaterial = Material(Vec3(1.0, 1.0, 1.0), Vec3(0.0, 0.0, 0.0), 0.0, Vec3(0.0,0.0,0.0));

#endif // !MATERIAL_H
