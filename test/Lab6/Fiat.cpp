#include "Fiat.h"
#include "Weather.h"
Fiat::Fiat()
{
	fCap = 60;
	fCons = 3;
	speed[Weather::Sun] = 70;
	speed[Weather::Rain] = 40;
	speed[Weather::Snow] = 20;
	brand = "Fiat";
}

float Fiat::timp(int vreme, int lung, bool& finish)
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

const char* Fiat::nume()
{
	return brand;
}

