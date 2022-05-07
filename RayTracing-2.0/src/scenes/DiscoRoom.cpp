#include "../../include/scenes/DiscoRoom.h"
#include "../../include/scenes/WhiteRoom.h"
#include "../../include/scenes/OpenRoom.h"
#include "../../include/utility/Uniform.h"
#include "../../include/objects/Sphere.h"
#include "../../include/objects/HalfSpace.h"

DiscoRoom::DiscoRoom(int nBalls, int nLights, int seed) {
	addBodiesFrom(OpenRoom());

	double correctionFactor = std::sqrt(nLights);

	srand(seed);
	for (int i = 0; i < nBalls; i++) {
		bodies.push_back(std::make_shared<Uniform>(std::make_shared<Sphere>(Vec3::randomVec().Z0toMP(), 0.1), blackMaterial.setDiffuse(Vec3(randomDouble(), randomDouble(), randomDouble())).setSpecular(Vec3(1.0,1.0,1.0)).setShininess(32)));
	}
	srand(2 * seed + 1);
	for (int i = 0; i < nLights; i++) {
		lights.push_back(std::make_shared<Light>(Vec3::randomVec().Z0toMP(), Vec3(randomDouble()/correctionFactor, randomDouble()/ correctionFactor, randomDouble()/ correctionFactor)));
	}
}