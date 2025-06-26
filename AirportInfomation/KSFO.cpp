#define KSFOLong -122.37482040732284
#define KSFOLat 37.619662189306695

#define SFO_StopBarHight 245

#define SFO_BOX_COUNT 4

#define SFO_NAME "San Francisco international airport"

#define NumOfAirports 1 // Put here, to change later, if value changes GetClosestAirport() might brake
#include <vector> 

struct SFObox
{
	double SFOcordnets[7];
	double SFO_RUN_HEADING;
};					