#pragma once
#include "Volvo.h"
#include "BMW.h"
#include "Seat.h"
#include "RangeRover.h"
#include "Fiat.h"
class Circuit
{
private:
	Car* masini[10];
	int nrMasini = 0;
	float timpMasina[10];
	bool finish[10];
	int lungime;
	int vreme;
public:
	Circuit();
	void SetLength(int);
	void SetWeather(int);
	void AddCar(Car*);
	void Race();
	void sortClasament();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

