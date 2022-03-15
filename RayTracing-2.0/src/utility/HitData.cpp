#include "../../include/utility/HitData.h"

HitData::HitData(double t, const Vec3& n) {
	this->t = t;
	this->n = n;
}

double HitData::getT() const{
	return t;
}

Vec3 HitData::getN() const{
	return n;
}

HitData HitData::from(const Hit& hit) {
	return HitData(getT(), getN());
}