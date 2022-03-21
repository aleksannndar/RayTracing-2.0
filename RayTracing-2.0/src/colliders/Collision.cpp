#include "../../include/colliders/Collision.h"

Collision::Collision(std::shared_ptr<Body> body, std::shared_ptr<Hit> hit) {
	this->body = body;
	this->hit = hit;
}

std::shared_ptr<Body> Collision::getBody() const {
	return body;
}

std::shared_ptr<Hit> Collision::getHit() const {
	return hit;
}