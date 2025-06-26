#pragma once
#include <vector>

double GetDistance(std::vector<double> LAT, std::vector<double> LONG, double End_lat, double End_LONG, int AircraftID);

double GetClosestAirport(std::vector<double> LAT, std::vector<double> LONG, double End_lat, double End_LONG);