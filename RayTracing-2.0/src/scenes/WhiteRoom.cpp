#include "../../include/scenes/WhiteRoom.h"
#include "../../include/utility/Uniform.h"
#include "../../include/objects/Sphere.h"
#include "../../include/objects/HalfSpace.h"

WhiteRoom::WhiteRoom() {
	bodies.push_back(std::make_shared<Uniform>(std::make_shared<HalfSpace>(Vec3(-1.0,0.0,0.0), Vec3(1.0,0.0,0.0))));
	bodies.push_back(std::make_shared<Uniform>(std::make_shared<HalfSpace>(Vec3(1.0, 0.0, 0.0), Vec3(-1.0, 0.0, 0.0))));
	bodies.push_back(std::make_shared<Uniform>(std::make_shared<HalfSpace>(Vec3(0.0, -1.0, 0.0), Vec3(0.0, 1.0, 0.0))));
	bodies.push_back(std::make_shared<Uniform>(std::make_shared<HalfSpace>(Vec3(0.0, 1.0, 0.0), Vec3(0.0, -1.0, 0.0))));
	bodies.push_back(std::make_shared<Uniform>(std::make_shared<HalfSpace>(Vec3(0.0, 0.0, -1.0), Vec3(0.0, 0.0, 1.0))));
	bodies.push_back(std::make_shared<Uniform>(std::make_shared<HalfSpace>(Vec3(0.0, 0.0, 1.0), Vec3(0.0, 0.0, -1.0))));

	lights.push_back(std::make_shared<Light>(Vec3(0.0,0.0,0.0),Vec3(1.0,1.0,1.0)));

	backgroundColor = Vec3(0.0, 0.0, 0.0);
}