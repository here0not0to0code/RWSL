#include "Great_Circle.h"
#include <vector>
#include <cmath>
#include "AirportInfomation\KSFO.cpp"
#define EARTH_RADIUS 6371.0 // KM

double GetDistance(std::vector<double> LAT, std::vector<double> LONG, double End_lat, double End_LONG, int AircraftID)
{
    double Latrad = (LAT[AircraftID - 1] * 3.1415926535) / 180;
    double Longrad = (LONG[AircraftID - 1] * 3.1415926535) / 180; // -1 cause it writes to 0 first dummy 
	double End_latRad = (End_lat * 3.1415926535) / 180; 
	double End_LONGrad = (End_LONG * 3.1415926535) / 180; 

    double Diff_lat = Latrad - End_latRad;
    double Diff_long = Longrad - End_LONGrad;

    double a = sin(Diff_lat / 2) * sin(Diff_lat / 2) +
        cos(Latrad) * cos(End_latRad) *
        sin(Diff_long / 2) * sin(Diff_long / 2);

    double Distance = (2 * atan2(sqrt(a), sqrt(1 - a)));

    return Distance * EARTH_RADIUS;
}

double GetClosestAirport(std::vector<double> LAT, std::vector<double> LONG, double End_lat, double End_LONG) // Gets the distance from every airport. soon to auto cheak, but need to possably change backend 
{
    double Distance;
    for (int i = 0; i < NumOfAirports; ++i)
    {
		Distance = GetDistance(LAT, LONG, End_lat, End_LONG, i);

        //Sorting agr here if i Add new airport, find shortest distance.... 
    }

    return Distance; 
}
