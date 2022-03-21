#include "../../include/scenes/Scene.h"

Scene:: Scene(std::vector<std::shared_ptr<Body>> bodies, const Vec3& backgroundColor) {
	this->bodies = bodies;
	this->backgroundColor = backgroundColor;
}

std::vector<std::shared_ptr<Body>> Scene::getBodies() const {
	return bodies;
}

Vec3 Scene::getBackgroundColor() const {
	return backgroundColor;
}