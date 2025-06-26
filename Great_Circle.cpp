#include "Great_Circle.h"
#include <vector>
#include <cmath>
#include "AirportInfomation\KSFO.cpp"
#define EARTH_RADIUS 6378137 // KM
#define PI 3.1415926535
#define DEG_TO_RAD_CONST (PI / 180)

#define GLM_ENABLE_EXPERIMENTAL

#include "glm/glm.hpp"
#include "glm/gtx/quaternion.hpp"

double DegRad(double DEG)
{
    return (DEG * (PI / 180));
}

static glm::vec3 rotate_first_point(glm::vec2 coord)
{
    glm::quat first = glm::angleAxis(coord.x, glm::vec3(0, 1, 0));
    glm::quat second = glm::angleAxis(coord.y, glm::vec3(1, 0, 0));

    glm::quat result = first * second;

    glm::mat3 rot = glm::mat3_cast(result);

    return glm::normalize(rot[2]);
}

glm::dvec3 get_xyz_from_coord(glm::vec2 coord, double alt)
{
    glm::dvec3 working_result = rotate_first_point(coord);

    return working_result * (alt + EARTH_RADIUS);
}

double GetDistance(glm::vec2 coord_0, glm::vec2 coord_1, int AircraftID)
{
    coord_0 *= DEG_TO_RAD_CONST;
    coord_1 *= DEG_TO_RAD_CONST;

    glm::vec3 first_direction = rotate_first_point(coord_0);
    glm::vec3 second_direction = rotate_first_point(coord_1);

    return (glm::acos(glm::dot(first_direction, second_direction)) * EARTH_RADIUS);
}

double GetClosestAirport(double Lat, double LONG, double End_Lat, double End_LONG) // Gets the distance from every airport. soon to auto cheak, but need to possably change backend 
{
    double Distance;
    for (int i = 0; i < NumOfAirports; ++i)
    {
		//Distance = GetDistance(Lat, LONG, End_Lat, End_LONG, i);

        //Sorting agr here if i Add new airport, find shortest distance.... 
    }

    return 0; 
}
