//THIS IS MAIN SRC FILE FOR RUNNING PROGRAM

#include<iostream>
#include "include/utility/MainHeader.h"
#include "include/utility/Color.h"
#include "include/utility/Camera.h"

Vec3 getColor(const Ray& r) {
	Vec3 unitDirection = unitVector(r.getDirection());
	double t = 0.5 * (unitDirection.getY() + 1.0);
	return (1.0 - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0);
}

int main() {

	double aspectRatio = 16.0 / 9.0;
	int imageHeight = 400;
	int imageWidth = imageHeight * aspectRatio;

	Camera cam = Camera(Vec3(0.0,0.0,0.0), Vec3(0.0,0.0,1.0), aspectRatio, 90.0);

	std::cout << "P3\n" << imageWidth << " " << imageHeight << "\n255\n";
	for (int i = imageHeight - 1; i >= 0 ; i--) {
		std::cerr << "\rremaining: " << i << " " << std::flush;
		Vec3 color;
		for (int j = imageWidth - 1; j >= 0 ; j--) {
			double v = (i*1.0) / (imageHeight - 1);
			double u = (j*1.0) / (imageWidth - 1);
			Ray r = cam.getRay(v, u);
			color = getColor(r);
			writeColor(color);
		}
	}
	std::cerr << "\ndone.\n";
}