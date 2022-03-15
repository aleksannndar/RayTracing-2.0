#include "../../include/utility/Color.h"

void writeColor(const Vec3& color) {
	std::cout << static_cast<int>(color.getX() * 255.99) << " " 
			<< static_cast<int>(color.getY() * 255.99) << " "
			<< static_cast<int>(color.getZ() * 255.99) << "\n";
}