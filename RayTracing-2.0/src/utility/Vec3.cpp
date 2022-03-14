#include "../../include/utility/Vec3.h"

#include<cmath>

Vec3::Vec3() {
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

Vec3::Vec3(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

double Vec3::getX() const {
	return x;
}

double Vec3::getY() const {
	return y;
}

double Vec3::getZ() const {
	return z;
}

Vec3 Vec3::operator-() const {
	return Vec3(-x, -y, -z);
}

Vec3& Vec3::operator+=(const Vec3& v) {
	x += v.getX();
	y += v.getY();
	z += v.getZ();
	return *this;
}

Vec3& Vec3::operator-=(const Vec3& v) {
	x -= v.getX();
	y -= v.getY();
	z -= v.getZ();
	return *this;
}

Vec3& Vec3::operator*=(const Vec3& v) {
	x *= v.getX();
	y *= v.getY();
	z *= v.getZ();
	return *this;
}

Vec3& Vec3::operator*=(double t) {
	x *= t;
	y *= t;
	z *= t;
	return *this;
}

Vec3& Vec3::operator/=(const Vec3& v) {
	x /= v.getX();
	y /= v.getY();
	z /= v.getZ();
	return *this;
}

Vec3& Vec3::operator/=(double t) {
	x /= t;
	y /= t;
	z /= t;
	return *this;
}

double Vec3::length() const {
	return std::sqrt(lengthSquared());
}

double Vec3::lengthSquared() const {
	return x * x + y * y + z * z;
}

std::ostream& operator<<(std::ostream& out, const Vec3& v) {
	return out << v.getX() << " " << v.getY() << " " << v.getZ();
}

Vec3 operator+(const Vec3& v, const Vec3& u) {
	return Vec3(v.getX() + u.getX(), v.getY() + u.getY(), v.getZ() + u.getZ());
}

Vec3 operator-(const Vec3& v, const Vec3& u) {
	return Vec3(v.getX() - u.getX(), v.getY() - u.getY(), v.getZ() - u.getZ());
}

Vec3 operator*(const Vec3& v, const Vec3& u) {
	return Vec3(v.getX() * u.getX(), v.getY() * u.getY(), v.getZ() * u.getZ());
}

Vec3 operator*(const Vec3& v, double t) {
	return Vec3(v.getX() * t, v.getY() * t, v.getZ() * t);
}

Vec3 operator*(double t,const Vec3& v) {
	return v*t;
}

Vec3 operator/(const Vec3& v, const Vec3& u) {
	return Vec3(v.getX() / u.getX(), v.getY() / u.getY(), v.getZ() / u.getZ());
}

Vec3 operator/(const Vec3& v, double t) {
	return (1/t)*v;
}

double dot(const Vec3& v, const Vec3& u) {
	return v.getX() * u.getX() + v.getY() * u.getY() + v.getZ() * u.getZ();
}

Vec3 cross(const Vec3& v, const Vec3& u) {
	return Vec3(v.getY()*u.getZ() - v.getZ()*u.getY(), 
				v.getZ()*u.getX() - v.getX()*u.getZ(), 
				v.getX()*u.getY() - v.getY()*u.getX());
}