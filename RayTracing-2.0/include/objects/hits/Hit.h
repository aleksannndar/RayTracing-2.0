#ifndef HIT_H
#define HIT_H

#include "../../utility/MainHeader.h"


class Hit {
public:
	//The time of the hit
	virtual double getT() const = 0;

	//Ray hit
	virtual Ray getRay() const = 0;
	
	//The normal at the point of the hit
	virtual Vec3 getN() const = 0;

	//Normalized normal at the point of the hit
	Vec3 n_() {
		return unitVector(getN());
	}
};

#endif

