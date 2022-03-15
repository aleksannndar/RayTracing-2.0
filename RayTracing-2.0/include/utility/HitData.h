#ifndef HIT_DATA_H
#define HIT_DATA_H

#include "Hit.h"

class HitData : public Hit {
private:
	double t;
	Vec3 n;
public:
	HitData(double t, const Vec3& n);

	double getT() const override;

	Vec3 getN() const override;

	HitData from(const Hit& hit);
};

#endif 
