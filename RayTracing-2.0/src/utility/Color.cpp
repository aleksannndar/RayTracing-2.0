#include "../../include/utility/Color.h"

void writeColor(const Vec3& color) {
	std::cout << color.getX() * 256.0 << " " << color.getY() * 256.0 << " " << color.getZ() * 256.0 << "\n";
}