#include "../../include/scenes/OpenRoom.h"
#include "../../include/utility/Uniform.h"
#include "../../include/objects/Sphere.h"
#include "../../include/objects/HalfSpace.h"

OpenRoom::OpenRoom() {
	bodies.push_back(std::make_shared<Uniform>(std::make_shared<HalfSpace>(Vec3(-1.0, 0.0, 0.0), Vec3(1.0, 0.0, 0.0))));
	bodies.push_back(std::make_shared<Uniform>(std::make_shared<HalfSpace>(Vec3(1.0, 0.0, 0.0), Vec3(-1.0, 0.0, 0.0))));
	bodies.push_back(std::make_shared<Uniform>(std::make_shared<HalfSpace>(Vec3(0.0, -1.0, 0.0), Vec3(0.0, 1.0, 0.0))));
	bodies.push_back(std::make_shared<Uniform>(std::make_shared<HalfSpace>(Vec3(0.0, 1.0, 0.0), Vec3(0.0, -1.0, 0.0))));
	bodies.push_back(std::make_shared<Uniform>(std::make_shared<HalfSpace>(Vec3(0.0, 0.0, -1.0), Vec3(0.0, 0.0, 1.0))));
	bodies.push_back(std::make_shared<Uniform>(std::make_shared<Sphere>(Vec3(0.5, 0.0, -0.3), 0.5), Vec3(1.0,0.0,0.0)));

	//lights.push_back(std::make_shared<Light>(Vec3(0.0, 0.0, 0.0), Vec3(0.5, 0.5, 0.5)));
	lights.push_back(std::make_shared<Light>(Vec3(-0.95, 0.0, -0.6), Vec3(0.5, 0.5, 0.5)));

	backgroundColor = Vec3(0.0, 0.0, 0.0);
}