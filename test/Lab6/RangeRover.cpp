#include "RangeRover.h"
#include "Weather.h"
RangeRover::RangeRover()
{
	fCap = 80;
	fCons = 5;
	speed[Weather::Sun] = 100;
	speed[Weather::Rain] = 75;
	speed[Weather::Snow] = 60;
	brand = "RangeRover";
}

float RangeRover::timp(int vreme, int lung, bool& finish)
{
	int viteza = speed[vreme];
	float efic = fCap / fCons;
	float autonomie = efic * viteza;
	if (autonomie > lung)
		finish = true;
	else
		finish = false;
	float timpul = efic * lung / autonomie;
	return timpul;
}

const char* RangeRover::nume()
{
	return brand;
}

