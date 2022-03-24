#ifndef MAIN_HEADER_H
#define MAIN_HEADER_H

#include "Ray.h"
#include "Vec3.h"
#include <cmath>
#include <limits>
#include <memory>
#include <cstdlib>

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;
const double epsilon = 1e-12;

double degreesToRadians(double degrees);

double randomDouble();

double randomDouble(double min, double max);

double clamp(double x, double min, double max);

#endif 

