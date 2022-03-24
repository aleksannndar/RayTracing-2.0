#include "../../include/scenes/Scene.h"

Scene:: Scene(std::vector<std::shared_ptr<Body>> bodies, std::vector<std::shared_ptr<Light>> lights, const Vec3& backgroundColor) {
	this->bodies = bodies;
	this->lights = lights;
	this->backgroundColor = backgroundColor;
}

std::vector<std::shared_ptr<Body>> Scene::getBodies() const {
	return bodies;
}

Vec3 Scene::getBackgroundColor() const {
	return backgroundColor;
}

std::vector<std::shared_ptr<Light>> Scene::getLights() const{
	return lights;
}