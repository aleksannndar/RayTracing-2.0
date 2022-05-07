#include "../../include/scenes/InitialScene.h"
#include "../../include/utility/Uniform.h"
#include "../../include/objects/Sphere.h"
#include "../../include/objects/HalfSpace.h"

InitialScene::InitialScene() {
	//Scene
	//Objects
	Vec3 specular = Vec3(1.0, 1.0, 1.0);
	double shininess = 32;

	std::shared_ptr<Uniform> o1 = std::make_shared<Uniform>(std::make_shared<Sphere>(Vec3(0.5, -1, -2.0), 1.0), blackMaterial.setDiffuse(Vec3(0.6, 0.4, 0.4)).setSpecular(specular).setShininess(shininess));
	std::shared_ptr<Uniform> o2 = std::make_shared<Uniform>(std::make_shared<HalfSpace>(Vec3(0.0, -1.0, 0.0), Vec3(0.0, 1.0, 0.0)), blackMaterial.setDiffuse(Vec3(0.7, 0.1, 0.1)).setSpecular(specular).setShininess(shininess));
	std::shared_ptr<Uniform> o3 = std::make_shared<Uniform>(std::make_shared<HalfSpace>(Vec3(1.0, 0.0, 0.0), Vec3(-1.0, 0.0, 0.0)), blackMaterial.setDiffuse(Vec3(0.1, 0.7, 0.1)).setSpecular(specular).setShininess(shininess));
	std::shared_ptr<Uniform> o4 = std::make_shared<Uniform>(std::make_shared<HalfSpace>(Vec3(0.0, 0.0, -3.0), Vec3(0.0, 0.0, 1.0)), blackMaterial.setDiffuse(Vec3(0.1, 0.1, 0.7)).setSpecular(specular).setShininess(shininess));

	bodies.push_back(o1);
	bodies.push_back(o2);
	bodies.push_back(o3);
	bodies.push_back(o4);

	//Lights
	std::shared_ptr<Light> l1 = std::make_shared<Light>(Vec3(0.0, 0.0, 0.0), Vec3(1.0, 1.0, 1.0));
	std::shared_ptr<Light> l2 = std::make_shared<Light>(Vec3(-3.0, 2.0, -1.0), Vec3(1.0, 1.0, 1.0));

	lights.push_back(l1);
	lights.push_back(l2);

	backgroundColor = Vec3(0.0, 0.0, 0.0);
}