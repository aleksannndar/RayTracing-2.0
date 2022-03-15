#ifndef VEC3_H
#define VEC3_H

#include<iostream>

class Vec3 {
private:
	double x;
	double y;
	double z;
public:
	Vec3();

	Vec3(double x, double y, double z);

	double getX() const;

	double getY() const;

	double getZ() const;

	Vec3 operator-() const;

	Vec3& operator+=(const Vec3& v);

	Vec3& operator-=(const Vec3& v);

	Vec3& operator*=(const Vec3& v);

	Vec3& operator*=(double t);

	Vec3& operator/= (const Vec3& v);

	Vec3& operator/= (double t);

	double length() const;

	double lengthSquared() const;

};

std::ostream& operator<<(std::ostream& out, Vec3& v);

Vec3 operator+(const Vec3& v, const Vec3& u);

Vec3 operator-(const Vec3& v, const Vec3& u);

Vec3 operator*(const Vec3& v, const Vec3& u);

Vec3 operator*(const Vec3& v, double t);

Vec3 operator*(double t, const Vec3& v);

Vec3 operator/(const Vec3& v, const Vec3& u);

Vec3 operator/(const Vec3& v, double t);

double dot(const Vec3& v, const Vec3& u);

Vec3 cross(const Vec3& v, const Vec3& u);

Vec3 unitVector(const Vec3& v);


#endif 
