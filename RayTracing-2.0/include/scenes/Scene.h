#ifndef SCENE_H
#define SCENE_H

#include <memory>
#include <vector>

#include "../utility/Body.h"
#include "../utility/Light.h"

class Scene {
protected:
	std::vector<std::shared_ptr<Body>> bodies;
	std::vector<std::shared_ptr<Light>> lights;
	Vec3 backgroundColor;
public:
	Scene() {};
	Scene(std::vector<std::shared_ptr<Body>> bodies, std::vector<std::shared_ptr<Light>> lights, const Vec3& backgroundColor);

	std::vector<std::shared_ptr<Body>> getBodies() const;

	Vec3 getBackgroundColor() const;

	std::vector<std::shared_ptr<Light>> getLights() const;

	void addBodiesFrom(const Scene& other);

	void addLightsFrom(const Scene& other);

	void addAll(const Scene& other);

};

#endif 

