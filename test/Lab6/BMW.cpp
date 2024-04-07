#include "BMW.h"
#include "Weather.h"
BMW::BMW()
{
	fCap = 100;
	fCons = 8;
	speed[Weather::Sun] = 120;
	speed[Weather::Rain] = 40;
	speed[Weather::Snow] = 25;
	brand = "BMW";
}

float BMW::timp(int vreme, int lung, bool& finish)
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

const char* BMW::nume()
{
	return brand;
}
