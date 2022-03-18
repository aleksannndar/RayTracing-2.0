#include "../../include/utility/Color.h"

void writeColor(const Vec3& color, int samplesPerPixel) {
	double r = color.getX();
	double g = color.getY();
	double b = color.getZ();

	double scale = 1.0 / samplesPerPixel;
	r = std::sqrt(r * scale);
	g = std::sqrt(g * scale);
	b = std::sqrt(b * scale);

	std::cout << static_cast<int>(color.getX() * 255.99) << " " 
			<< static_cast<int>(color.getY() * 255.99) << " "
			<< static_cast<int>(color.getZ() * 255.99) << "\n";
}