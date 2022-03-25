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

void Scene::addBodiesFrom(const Scene& other) {
	for (std::shared_ptr<Body> b : other.getBodies()) {
		bodies.push_back(b);
	}
}


void Scene::addLightsFrom(const Scene& other) {
	for (std::shared_ptr<Light> l : other.getLights()) {
		lights.push_back(l);
	}
}

void Scene::addAllFrom(const Scene& other) {
	addBodiesFrom(other);
	addLightsFrom(other);
}

