#pragma once
#include <vector>

#include "glm/glm.hpp"

glm::dvec3 get_xyz_from_coord(glm::vec2 coord, double alt);
double GetDistance(glm::vec2 coord_0, glm::vec2 coord_1, int AircraftID);

double GetClosestAirport(double LAT, double LONG, double End_lat, double End_LONG);