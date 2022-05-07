//THIS IS MAIN SRC FILE FOR RUNNING PROGRAM

#include "include/utility/Vec3.h"
#include<iostream>
#include<vector>
#include "include/utility/MainHeader.h"
#include "include/utility/Color.h"
#include "include/utility/Camera.h"
#include "include/objects/Sphere.h"
#include "include/objects/HalfSpace.h"
#include "include/utility/Uniform.h"
#include "include/raytracers/RayTracerSimple.h"
#include "include/colliders/BruteForceCollider.h"
#include "include/utility/Material.h"
#include "include/raytracers/Sonar.h"
#include "include/utility/Light.h"
#include "include/scenes/InitialScene.h"
#include "include/scenes/DiscoRoom.h"
#include "include/scenes/OpenRoom.h"

int main() {

	double aspectRatio = 1.0;
	int imageHeight = 720;
	int imageWidth = imageHeight * aspectRatio;
	int samplesPerPixel = 10;

	//Scene
	std::shared_ptr<Scene> scene = std::make_shared<DiscoRoom>(20, 6, 11679);
	//std::shared_ptr<Scene> scene = std::make_shared<InitialScene>();
	//Collider
	std::shared_ptr<BruteForceCollider> collider = std::make_shared<BruteForceCollider>(scene->getBodies());

	//Camera
	Camera cam = Camera(Vec3(0.0,0.0,2.0), Vec3(0.0,0.0,0.0), aspectRatio, 50.0);

	//RayTracer
	std::shared_ptr<RayTracer> rayTracer = std::make_shared<RayTracerSimple>(scene, collider);

	std::cout << "P3\n" << imageWidth << " " << imageHeight << "\n255\n";
	for (int i = imageHeight - 1; i >= 0; --i) {
		std::cerr << "\rremaining: " << i << " " << std::flush;
		for (int j = imageWidth - 1; j >= 0; --j) {
			Vec3 color = Vec3(0.0, 0.0, 0.0);
			for (int k = 0; k < samplesPerPixel; k++) {
				double u = (j + (randomDouble() - 0.5) * 2.0) / (imageWidth - 1);
				double v = (i + (randomDouble() - 0.5) * 2.0) / (imageHeight - 1);
				Ray r = cam.getRay(u, v);
				color += rayTracer->sample(r);
			}
			writeColor(color, samplesPerPixel);
		}
	}
	std::cerr << "\ndone.\n";
}