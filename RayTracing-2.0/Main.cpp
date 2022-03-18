//THIS IS MAIN SRC FILE FOR RUNNING PROGRAM

#include "include/utility/Vec3.h"
#include<iostream>
#include "include/utility/MainHeader.h"
#include "include/utility/Color.h"
#include "include/utility/Camera.h"
#include "include/objects/Sphere.h"
#include "include/objects/HalfSpace.h"
#include "include/utility/Uniform.h"

Vec3 getColor(const Ray& r) {
	Uniform uniSphere = Uniform(std::make_shared<Sphere>(Vec3(0.0, -1, -1.0), 0.5), Vec3(0.6, 0.4, 0.4));
	Uniform uniHS = Uniform(std::make_shared<HalfSpace>(Vec3(0.0, -1.0, 0.0), Vec3(0.0, 1.0, 0.0)), Vec3(0.7, 0.7, 0.7));
	std::shared_ptr<Hit> sHit = uniSphere.getSolid()->firstHit(r, 0.0);
	std::shared_ptr<Hit> hsHit = uniHS.getSolid()->firstHit(r, 0.0);
	if (sHit != nullptr && hsHit != nullptr) {
		if (sHit->getT() <= hsHit->getT()) {
			return uniSphere.materialAt(*sHit);
		}
		else {
			return uniHS.materialAt(*hsHit);
		}
	}
	else if (hsHit != nullptr) {
		return uniHS.materialAt(*hsHit);
	}
	else if (sHit != nullptr) {
		return uniSphere.materialAt(*sHit);
	}
	Vec3 unitDirection = unitVector(r.getDirection());
	double t = 0.5 * (unitDirection.getY() + 1.0);
	return (1.0 - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0);
}

int main() {

	double aspectRatio = 16.0 / 9.0;
	int imageHeight = 400;
	int imageWidth = imageHeight * aspectRatio;
	int samplesPerPixel = 10;

	Camera cam = Camera(Vec3(0.0,0.0,0.0), Vec3(0.0,0.0,-1.0), aspectRatio, 90.0);

	std::cout << "P3\n" << imageWidth << " " << imageHeight << "\n255\n";
	for (int i = imageHeight - 1; i >= 0; i--) {
		std::cerr << "\rremaining: " << i << " " << std::flush;
		Vec3 color = Vec3(0.0,0.0,0.0);
		for (int j = 0; j < imageWidth; j++) {
			for (int k = 0; k < samplesPerPixel; k++) {
				double u = (j + (randomDouble() - 0.5)*2.0) / (imageWidth - 1);
				double v = (i + (randomDouble() - 0.5) * 2.0) / (imageHeight - 1);
				Ray r = cam.getRay(u, v);
				color += getColor(r);
				writeColor(color, samplesPerPixel);
			}
		}
	}
	std::cerr << "\ndone.\n";
}