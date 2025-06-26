#include "Great_Circle.h"
#include <vector>
#include <cmath>
#include "AirportInfomation\KSFO.cpp"
#define EARTH_RADIUS 6371.0

double GetDistance(std::vector<double> LAT, std::vector<double> LONG, double End_lat, double End_LONG, int AircraftID)
{
    double Latrad = (LAT[AircraftID] * 3.1415926535) / 180;
    double Longrad = (LONG[AircraftID] * 3.1415926535) / 180;

    double Diffrence_lat = Latrad - End_lat;
    double Diffrance_long = Longrad - End_LONG;

    double A = sin(Diffrence_lat / 2) * sin(Diffrence_lat / 2) +
        cos(Latrad) * cos(Latrad) *
        sin(Diffrance_long / 2) * sin(Diffrance_long / 2);

    double C = 2 * atan2(sqrt(A), sqrt(1 - A));

    return EARTH_RADIUS * C;
}

double GetClosestAirport(std::vector<double> LAT, std::vector<double> LONG, double End_lat, double End_LONG) // Gets the distance from every airport. soon to auto cheak, but need to possably change backend 
{
    for (int i; i < NumOfAirports; ++i)
    {
		GetDistance(LAT, LONG, End_lat, End_LONG, i);
    } 
}
