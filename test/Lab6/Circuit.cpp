#include <iostream>
#include "Car.h"
#include "Weather.h"
#include "Circuit.h"
#include <string>

Circuit::Circuit()
{
	nrMasini = 0;
}

void Circuit::SetLength(int lung)
{
	lungime = lung;
}

void Circuit::SetWeather(int stare)
{
	vreme = stare;
}

void Circuit::AddCar(Car* brand)
{
	masini[nrMasini] = brand;
	this->nrMasini++;
}

void Circuit::Race()
{
	for (int i = 0; i < nrMasini; i++)
	{
		bool aux;
		timpMasina[i] = masini[i]->timp(vreme,lungime,aux);
		finish[i] = aux;
	}
}

void Circuit::sortClasament()
{
	bool ok;
	do
	{
		ok = true;
		for (int i = 0; i < nrMasini; i++)
		{
			if (timpMasina[i] > timpMasina[i + 1])
			{
				ok = false;

				Car* aux = masini[i];
				masini[i] = masini[i + 1];
				masini[i + 1] = aux;

				bool fin = finish[i];
				finish[i] = finish[i + 1];
				finish[i + 1] = fin;

				float tmp = timpMasina[i];
				timpMasina[i] = timpMasina[i + 1];
				timpMasina[i + 1] = tmp;
			}
		}
	} while (ok == false);
}

void Circuit::ShowFinalRanks()
{
	int loc = 1;
	for (int i = 0; i < nrMasini; i++)
	{
		std::cout << "Locul " << loc << ": " << masini[i]->nume(); 
		std::cout<< " " << timpMasina[i] << "\n";
		if (timpMasina[i] != timpMasina[i + 1])
			loc++;
	}
}

void Circuit::ShowWhoDidNotFinish()
{
	for (int i = 0; i < nrMasini; i++)
		if (finish == 0)
			std::cout << masini[i]->nume() << "nu a terminat cursa." << "\n";
}
