#ifndef SCENE_H
#define SCENE_H

#include <memory>
#include <vector>

#include "../utility/Body.h"

class Scene {
private:
	std::vector<std::shared_ptr<Body>> bodies;
public:
	Scene(std::vector<std::shared_ptr<Body>> bodies);

	std::vector<std::shared_ptr<Body>> getBodies() const;

};

#endif 

