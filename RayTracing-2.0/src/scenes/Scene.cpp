#include "../../include/scenes/Scene.h"

Scene:: Scene(std::vector<std::shared_ptr<Body>> bodies) {
	this->bodies = bodies;
}

std::vector<std::shared_ptr<Body>> Scene::getBodies() const {
	return bodies;
}