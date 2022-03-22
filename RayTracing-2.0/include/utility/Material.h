#ifndef MATERIAL_H
#define MATERIAL_H

#include "MainHeader.h"

class Material {
private:
	Vec3 diffuse;
public:
	Material() {};
	Material(const Vec3& diffuse);

	Vec3 getDiffuse() const;

};

#endif // !MATERIAL_H
