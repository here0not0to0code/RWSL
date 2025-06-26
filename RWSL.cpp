#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <strsafe.h>
#include <simpdata.h>
#include <vector>
#include <exception>

#include "AirportInfomation\KSFO.cpp"
#include "Rotate_Translate.h"
#include "SimConnect.h"
#include "Great_Circle.h"

HANDLE hSimConnect = NULL;


std::vector<double> Aircraftlat;
std::vector<double> Aircraftlon;
std::vector<double> Aircraftalt; 
std::vector<double> Aircraftairspeed;
std::vector<bool> insideBox; 

std::vector<double> Player_lat;
std::vector<double> Player_long;
std::vector<double> Player_alt;
std::vector<double> Player_airspeed;

int i = 0;
int NumOfAircraft;
int j = 0;

SFObox SFObox1;



static enum DATA_DEFINE_ID {
    DEFINITION_1,
};
static enum DATA_REQUEST_ID {
	REQUEST1
};

struct AircraftData {
    double latitude;
    double longitude;
    double altitude;
    double Airspeed;
};

bool SimOpen()
{
    HRESULT hr;
    
    if (SUCCEEDED(SimConnect_Open(&hSimConnect, "RWSL", NULL, 0, 0, 0)))
    {
        printf("\nConnected to Flight Simulator! \n");
        return true; 
    }
    else
    {
        ++j;
        printf("\nCould not Connect to Flight Simulator!\n \n"); 
        if (j == 3)
        {
            printf("Returning..."); 
            return false;
        }
        printf("Trying again in 3 \n");
        Sleep(1000);
        printf("2\n");
        Sleep(1000);
        printf("1\n");
        Sleep(1000);

        SimOpen();
    }
}
void SimClose()
{
    HRESULT hr;
    printf("\nConnection Closed.");
}

bool Boxcheak(int NumOfAircraft, int AircraftID)
{
    for (int Inc = 0; i < NumOfAircraft; Inc++)
    {
        
    }
    return true;
}


void CALLBACK MyDispatchProc(SIMCONNECT_RECV* pData, DWORD cbData, void* pContext)
{
    switch (pData->dwID)
    {
        case SIMCONNECT_RECV_ID_SIMOBJECT_DATA_BYTYPE:
        {
         SIMCONNECT_RECV_SIMOBJECT_DATA* pObjData = (SIMCONNECT_RECV_SIMOBJECT_DATA*)pData;
             if (pObjData->dwRequestID == REQUEST1)
             {
                 AircraftData* data = (AircraftData*)&pObjData->dwData;
                 printf("Latitude: %f, Longitude: %f, Altitude: %f, Speed: %f, \n", data->latitude, data->longitude, data->altitude, data->Airspeed);
                 ++i;
                 NumOfAircraft = i;
                 Aircraftlat.push_back(data->latitude);
                 Aircraftlon.push_back(data->longitude);
                 Aircraftalt.push_back(data->altitude);
                 Aircraftairspeed.push_back(data->Airspeed);
                 insideBox.push_back(NumOfAircraft);
                 std::cout << i << '\n' << '\n';
                 std::cout << "Distance between" << SFO_NAME << " and Aircraft is " << GetDistance(Aircraftlat, Aircraftlon, KSFOLat, KSFOLong, i);

                 // Boxcheak(NumOfAircraft, i);
             }           
        }
    }
}

int main()
{
    SFObox1.SFOcordnets[0] = 37.60538626597869;
    SFObox1.SFOcordnets[1] = -122.38248229045143;
    SFObox1.SFOcordnets[2] = 37.605259539282606;
    SFObox1.SFOcordnets[3] = -122.38124521919424; 
    SFObox1.SFOcordnets[4] = 37.627864457616;
    SFObox1.SFOcordnets[5] = -122.36625576956017;
    SFObox1.SFOcordnets[6] = 37.62796601502269;
    SFObox1.SFOcordnets[7] = -122.36756234938098; // not a issue 

    if (!SimOpen()) 
    {
        return 1; 
    }

    SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PLANE LATITUDE", "degree");
    SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PLANE LONGITUDE", "degrees");
    SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "PLANE ALTITUDE", "feet");
    SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "AIRSPEED TRUE", "knots"); 
    SimConnect_AddToDataDefinition(hSimConnect, DEFINITION_1, "Initial Position", "NULL", SIMCONNECT_DATATYPE_INITPOSITION, 0);

    
  
    while (true)
    {
        SimConnect_RequestDataOnSimObjectType(hSimConnect, REQUEST1, DEFINITION_1, 4000, SIMCONNECT_SIMOBJECT_TYPE_AIRCRAFT);
        SimConnect_CallDispatch(hSimConnect, MyDispatchProc, NULL);
        Sleep(2000);
        system("cls");
        i = 0; 

        Aircraftlat.clear();
        Aircraftlon.clear();
        Aircraftairspeed.clear();
        Aircraftalt.clear();
        insideBox.clear();
        
    }

}
