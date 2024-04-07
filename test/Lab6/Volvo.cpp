#include "Volvo.h"
#include "Weather.h"
Volvo::Volvo()
{
	fCap = 80;
	fCons = 5;
	speed[Weather::Sun] = 90;
	speed[Weather::Rain] = 60;
	speed[Weather::Snow] = 30;
	brand = "Volvo";
}

float Volvo::timp(int vreme, int lung, bool& finish)
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

const char* Volvo::nume()
{
	return brand;
}

