#include "Seat.h"
#include "Weather.h"
Seat::Seat()
{
	fCap = 120;
	fCons = 10;
	speed[Weather::Sun] = 80;
	speed[Weather::Rain] = 50;
	speed[Weather::Snow] = 35;
	brand = "Seat";
}

float Seat::timp(int vreme, int lung, bool& finish)
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

const char* Seat::nume()
{
	return brand;
}

