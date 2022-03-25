#include "../../include/utility/MainHeader.h"

double degreesToRadians(double degrees) {
	return degrees * pi / 180;
}

double randomDouble() {
	return double(rand()) / (RAND_MAX + 1);
}

double randomDouble(double min, double max) {
	return min + (max - min) * randomDouble();
}

double clamp(double x, double min, double max) {
	if (x < min)
		return min;
	if (x > max)
		return max;
	return x;
}