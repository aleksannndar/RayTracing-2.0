#include "../../include/scenes/TestScene.h"
#include "../../include/utility/Uniform.h"
#include "../../include/objects/Sphere.h"
#include "../../include/objects/HalfSpace.h"

TestScene::TestScene() {
	bodies.push_back(std::make_shared<Uniform>(std::make_shared<HalfSpace>(Vec3(-1.0, 0.0, 0.0), Vec3(1.0, 0.0, 0.0)), defaultMaterial.setDiffuse(Vec3(0.8, 0.0, 0.0))));
	bodies.push_back(std::make_shared<Uniform>(std::make_shared<HalfSpace>(Vec3(1.0, 0.0, 0.0), Vec3(-1.0, 0.0, 0.0)), defaultMaterial.setDiffuse(Vec3(0.0, 0.8, 0.0))));
	bodies.push_back(std::make_shared<Uniform>(std::make_shared<HalfSpace>(Vec3(0.0, -1.0, 0.0), Vec3(0.0, 1.0, 0.0)), defaultMaterial));
	bodies.push_back(std::make_shared<Uniform>(std::make_shared<HalfSpace>(Vec3(0.0, 1.0, 0.0), Vec3(0.0, -1.0, 0.0)), defaultMaterial));
	bodies.push_back(std::make_shared<Uniform>(std::make_shared<HalfSpace>(Vec3(0.0, 0.0, -1.0), Vec3(0.0, 0.0, 1.0)), defaultMaterial));
	bodies.push_back(std::make_shared<Uniform>(std::make_shared<Sphere>(Vec3(0.0, 0.0, -0.5), 0.35), defaultMaterial.setDiffuse(Vec3(0.0,0.0,0.0)).setRefractive(Vec3(1.0, 1.0, 1.0))));

	lights.push_back(std::make_shared<Light>(Vec3(0.5, 0.9, -0.75), Vec3(0.2, 0.2, 0.2)));
	lights.push_back(std::make_shared<Light>(Vec3(0.5, 0.9, 0.75), Vec3(0.2, 0.2, 0.2)));
	lights.push_back(std::make_shared<Light>(Vec3(-0.5, 0.9, 0.75), Vec3(0.2, 0.2, 0.2)));
	lights.push_back(std::make_shared<Light>(Vec3(-0.5, 0.9, -0.75), Vec3(0.2, 0.2, 0.2)));
	//lights.push_back(std::make_shared<Light>(Vec3(0.0, 0.0, 2), Vec3(1.0, 1.0, 1.0)));

	backgroundColor = Vec3(0.0, 0.0, 0.0);
}