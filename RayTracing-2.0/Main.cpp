//THIS IS MAIN SRC FILE FOR RUNNING PROGRAM

#include<iostream>
#include "include/utility/MainHeader.h"
#include "include/utility/Color.h"



int main() {
	Vec3 blue(0.0,0.0,0.3);

	double aspectRatio = 16.0 / 9.0;
	int imageHeight = 400;
	int imageWidth = imageHeight * aspectRatio;

	std::cout << "P3\n" << imageWidth << " " << imageHeight << "\n255\n";
	for (int i = imageHeight - 1; i >= 0 ; i--) {
		std::cerr << "\rremaining: " << i << " " << std::flush;
		for (int j = imageWidth - 1; j >= 0 ; j--) {
			writeColor(blue);
		}
	}
	std::cerr << "\ndone.\n";
}