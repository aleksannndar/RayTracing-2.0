#ifndef SCENE_H
#define SCENE_H

#include <memory>
#include <vector>

#include "../utility/Body.h"

class Scene {
private:
	std::vector<std::shared_ptr<Body>> bodies;
	Vec3 backgroundColor;
public:
	Scene(std::vector<std::shared_ptr<Body>> bodies, const Vec3& backgroundColor);

	std::vector<std::shared_ptr<Body>> getBodies() const;

	Vec3 getBackgroundColor() const;

};

#endif 

