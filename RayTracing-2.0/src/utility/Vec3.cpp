#include "../../include/utility/Vec3.h"
#include "../../include/utility/MainHeader.h"
#include<cmath>

Vec3::Vec3(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vec3::Vec3() {
	Vec3(0.0, 0.0, 0.0);
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

std::ostream& operator<<(std::ostream& out, Vec3& v) {
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

Vec3 unitVector(const Vec3& v) {
	return v / v.length();
}

Vec3 normal(const Vec3& v) {
	if (v.getX() != 0 || v.getY() != 0) {
		return Vec3(-v.getY(), v.getX(), 0.0);
	}
	else {
		return Vec3(1.0, 0.0, 0.0);
	}
}

bool operator ==(const Vec3& v, const Vec3& u) {
	return (v.getX() == u.getX() && v.getY() == u.getY() && v.getZ() == u.getZ());
}

bool operator !=(const Vec3& v, const Vec3& u) {
	return (v.getX() != u.getX() || v.getY() != u.getY() || v.getZ() != u.getZ());
}

Vec3 Vec3::randomVec(){
	return Vec3(randomDouble(), randomDouble(), randomDouble());
}

Vec3& Vec3::Z0toMP() {
	x *= 2.0;
	y *= 2.0;
	z *= 2.0;

	x -= 1;
	y -= 1;
	z -= 1;
	
	return *this;
}

Vec3& Vec3::MPtoZ0() {
	x += 1;
	y += 1;
	z += 1;

	x /= 2.0;
	y /= 2.0;
	z /= 2.0;

	return *this;
}

Vec3 reflected(const Vec3& r, const Vec3& n) {
	return r - 2 * (r - (dot(n, r) * n / n.lengthSquared()));
}

Vec3 reflectedN(const Vec3& r, const Vec3& n) {
	return r - 2 * (r - (dot(n, r) * n));
}
