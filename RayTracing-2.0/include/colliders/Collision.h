#ifndef COLLISION_H
#define COLLISION_H

#include <memory>
#include "../utility/Body.h"

class Collision {
private:
	std::shared_ptr<Body> body;
	std::shared_ptr<Hit> hit;
public:
	Collision(std::shared_ptr<Body> body, std::shared_ptr<Hit> hit);

	std::shared_ptr<Body> getBody() const;
	std::shared_ptr<Hit> getHit() const;
};

#endif