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


//Vec3 getColor(const Ray& r) {
//	std::shared_ptr<Uniform> o1 = std::make_shared<Uniform>(std::make_shared<Sphere>(Vec3(1.0, -1, -2.0), 1.0), Vec3(0.6, 0.4, 0.4));
//	std::shared_ptr<Uniform> o2 = std::make_shared<Uniform>(std::make_shared<HalfSpace>(Vec3(0.0, -1.0, 0.0), Vec3(0.0, 1.0, 0.0)), Vec3(0.7, 0.1, 0.1));
//	std::shared_ptr<Uniform> o3 = std::make_shared<Uniform>(std::make_shared<HalfSpace>(Vec3(1.0, 0.0, 0.0), Vec3(-1.0, 0.0, 0.0)), Vec3(0.1, 0.7, 0.1));
//	
//	std::vector<std::shared_ptr<Body>> bodies;
//	bodies.push_back(o1);
//	bodies.push_back(o2);
//	bodies.push_back(o3);
//
//	Vec3 m = getMaterial(r, bodies);
//	return m;
//
//	Vec3 unitDirection = unitVector(r.getDirection());
//	double t = 0.5 * (unitDirection.getY() + 1.0);
//	return (1.0 - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0);
//}

int main() {

	double aspectRatio = 16.0 / 9.0;
	int imageHeight = 400;
	int imageWidth = imageHeight * aspectRatio;
	int samplesPerPixel = 10;

	//Scene
	std::shared_ptr<Uniform> o1 = std::make_shared<Uniform>(std::make_shared<Sphere>(Vec3(1.0, -1, -2.0), 1.0), Material(Vec3(0.6, 0.4, 0.4)));
	std::shared_ptr<Uniform> o2 = std::make_shared<Uniform>(std::make_shared<HalfSpace>(Vec3(0.0, -1.0, 0.0), Vec3(0.0, 1.0, 0.0)), Material(Vec3(0.7, 0.1, 0.1)));
	std::shared_ptr<Uniform> o3 = std::make_shared<Uniform>(std::make_shared<HalfSpace>(Vec3(1.0, 0.0, 0.0), Vec3(-1.0, 0.0, 0.0)), Material(Vec3(0.1, 0.7, 0.1)));

	std::vector<std::shared_ptr<Body>> bodies;
	bodies.push_back(o1);
	bodies.push_back(o2);
	bodies.push_back(o3);

	std::shared_ptr<Scene> scene = std::make_shared<Scene>(bodies, Vec3(0.0,0.0,0.0));

	//Collider
	std::shared_ptr<BruteForceCollider> collider = std::make_shared<BruteForceCollider>(bodies);

	//Camera
	Camera cam = Camera(Vec3(0.0,0.0, 0.0), Vec3(0.0,0.0,-1.0), aspectRatio, 90.0);

	//RayTracer
	std::shared_ptr<RayTracer> rayTracer = std::make_shared<Sonar>(scene, collider);

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