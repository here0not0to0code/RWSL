#include "Great_Circle.h"
#include <vector>
#include <cmath>
#include "AirportInfomation\KSFO.cpp"
#define EARTH_RADIUS 6371.0 // KM
#define PI 3.1415926535

double DegRad(double DEG)
{
    return (DEG * (PI / 180));
}

double GetDistance(double Lat, double LONG, double End_Lat, double End_LONG, int AircraftID)
{
    double Latrad = DegRad(Lat);
    double Longrad = DegRad(LONG);
    double End_LatRad = DegRad(End_LONG);
    double End_LONGrad = DegRad(End_LONG);

    double Diff_LatRad = Latrad - End_LatRad;
    double Diff_longRad = Longrad - End_LONGrad;

    double a = sin(Diff_LatRad / 2) * sin(Diff_LatRad / 2) +
        cos(Latrad) * cos(End_LatRad) *
        sin(Diff_longRad / 2) * sin(Diff_longRad / 2);

    double Distance = (2 * atan2(sqrt(a), sqrt(1 - a)));

    return Distance * EARTH_RADIUS ;
}

double GetClosestAirport(double Lat, double LONG, double End_Lat, double End_LONG) // Gets the distance from every airport. soon to auto cheak, but need to possably change backend 
{
    double Distance;
    for (int i = 0; i < NumOfAirports; ++i)
    {
		Distance = GetDistance(Lat, LONG, End_Lat, End_LONG, i);

        //Sorting agr here if i Add new airport, find shortest distance.... 
    }

    return Distance; 
}
