#ifndef BODY_H
#define BODY_H

#include "MainHeader.h"
#include "Solid.h"
#include "Material.h"
#include <memory>

class Body {
public:
	virtual std::shared_ptr<Solid> getSolid() const = 0;

	//CREATE CLASS FOR MATERIAL
	virtual Material materialAt(const Hit& hit) const = 0;
};

#endif

