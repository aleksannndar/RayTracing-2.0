#ifndef INITIAL_SCENE_H
#define INITIAL_SCENE_H

#include "Scene.h"

class InitialScene : public Scene {
public:
	InitialScene();

	InitialScene(std::vector<std::shared_ptr<Body>> bodies, std::vector<std::shared_ptr<Light>> lights, const Vec3& backgroundColor) : Scene(bodies, lights, backgroundColor);
};

#endif 

