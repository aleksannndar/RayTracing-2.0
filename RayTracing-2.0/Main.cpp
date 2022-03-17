//THIS IS MAIN SRC FILE FOR RUNNING PROGRAM

#include "include/utility/Vec3.h"
#include<iostream>
#include "include/utility/MainHeader.h"
#include "include/utility/Color.h"
#include "include/utility/Camera.h"
#include "include/objects/Sphere.h"
#include "include/objects/HalfSpace.h"
#include "include/utility/Uniform.h"

Vec3 getColor(const Ray& r, const Uniform& sphere, const Uniform& hs) {
	std::shared_ptr<Hit> sHit = sphere.getSolid()->firstHit(r, -1.0);
	std::shared_ptr<Hit> hsHit = hs.getSolid()->firstHit(r, -1.0);
	if (sHit != nullptr && hsHit != nullptr) {
		if (sHit->getT() <= hsHit->getT()) {
			return sphere.materialAt(*sHit);
		}
		else {
			return hs.materialAt(*hsHit);
		}
	}
	else if (hsHit != nullptr) {
		return hs.materialAt(*hsHit);
	}
	else if (sHit != nullptr) {
		return sphere.materialAt(*sHit);
	}
	Vec3 unitDirection = unitVector(r.getDirection());
	double t = 0.5 * (unitDirection.getY() + 1.0);
	return (1.0 - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0);
}

int main() {

	double aspectRatio = 16.0 / 9.0;
	int imageHeight = 400;
	int imageWidth = imageHeight * aspectRatio;

	Camera cam = Camera(Vec3(0.0,0.0,0.0), Vec3(0.0,0.0,1.0), aspectRatio, 90.0);
	Uniform uniSphere = Uniform(std::make_shared<Sphere>(Vec3(0.0, 0.0, -1.0), 0.6), Vec3(0.6,0.4,0.4));
	Uniform uniHS = Uniform(std::make_shared<HalfSpace>(Vec3(0.0, 0.0, 0.0), Vec3(0.0, 1.0, 0.0)), Vec3(0.7,0.7,0.7));

	std::cout << "P3\n" << imageWidth << " " << imageHeight << "\n255\n";
	for (int i = 0; i < imageHeight ; i++) {
		std::cerr << "\rremaining: " << i << " " << std::flush;
		Vec3 color;
		for (int j = imageWidth - 1; j >= 0 ; j--) {
			double v = (i*1.0) / (imageHeight - 1);
			double u = (j*1.0) / (imageWidth - 1);
			Ray r = cam.getRay(v, u);
			color = getColor(r, uniSphere, uniHS);
			writeColor(color);
		}
	}
	std::cerr << "\ndone.\n";
}