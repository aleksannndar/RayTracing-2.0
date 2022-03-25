#include "../../include/scenes/DiscoRoom.h"
#include "../../include/scenes/WhiteRoom.h"
#include "../../include/utility/Uniform.h"
#include "../../include/objects/Sphere.h"
#include "../../include/objects/HalfSpace.h"

DiscoRoom::DiscoRoom(int nBalls, int nLights, int seed) {
	addBodiesFrom(WhiteRoom());

	srand(seed);
	for (int i = 0; i < nBalls; i++) {
		bodies.push_back(std::make_shared<Uniform>(std::make_shared<Sphere>(Vec3::randomVec().Z0toMP(), 0.1), Vec3(randomDouble(), randomDouble(), randomDouble())));
	}
	srand(2 * seed + 1);
	for (int i = 0; i < nLights; i++) {
		lights.push_back(std::make_shared<Light>(Vec3::randomVec().Z0toMP(), Vec3(randomDouble()/3, randomDouble()/3, randomDouble()/3)));
	}
}