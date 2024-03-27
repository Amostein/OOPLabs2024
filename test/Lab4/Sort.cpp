#include "Sort.h"
#include <iostream>
#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
using namespace std;

Sort::~Sort()
{
	delete[] vector;
}
Sort::Sort(int nrElemente, int min, int max)
{
	vector = new int[nrElemente];
	size = nrElemente;
	time_t t;
	srand((unsigned)time(&t));
	for (int i = 0; i < size; i++) 
		vector[i] = min + rand() % (max - min + 1);
}
Sort::Sort(int* vector1, int nrElemente)
{
	vector = new int[nrElemente];
	size = nrElemente;
	for (int i = 0; i < nrElemente; i++) 
		vector[i] = vector1[i];
}
Sort::Sort(const char* valori)
{
	int i = 0, nr = 0, j = -1, nrLit = 0, size_vector = 1;
	while (valori[i] != '\0') {
		nrLit++;
		if (valori[i] == ',')
			size_vector++;
		i++;
	}
	size = size_vector;
	vector = new int[size];

	for (i = 0; i < nrLit; i++) {
		if (valori[i] == ',') {
			vector[++j] = nr;
			nr = 0;
		}
		else
			nr = nr * 10 + valori[i] - '0';
	}
	vector[++j] = nr;
}
Sort::Sort(int nrArgumente, ...)
{
	va_list argumente;
	va_start(argumente, nrArgumente);
	size = nrArgumente;
	vector = new int[size];
	for (int i = 0; i < nrArgumente; i++)
		vector[i] = va_arg(argumente, int);
	va_end(argumente);
}
void Sort::InsertSort(bool ascendent)
{
	int i, key,j;
	if (ascendent)
		for (i = 1; i < this->size; i++)
		{
			key = this->vector[i];
			j = i - 1;
			while (j >= 0 && this->vector[j] > key)
			{
				this->vector[j + 1] = this->vector[j];
				j--;
			}
			this->vector[j + 1] = key;

		}
	else
		for (i = 1; i < this->size; i++)
		{
			key = this->vector[i];
			j = i - 1;
			while (j >= 0 && this->vector[j] < key)
			{
				this->vector[j + 1] = this->vector[j];
				j--;
			}
			this->vector[j + 1] = key;
		}
}
void quickAs(int v[],int st, int dr)
{
	if (st < dr)
	{
		//pivotul este inițial v[st]
		int m = (st + dr) / 2;
		int aux = v[st];
		v[st] = v[m];
		v[m] = aux;
		int i = st, j = dr, d = 0;
		while (i < j)
		{
			if (v[i] > v[j])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				d = 1 - d;
			}
			i += d;
			j -= 1 - d;
		}
		quickAs(v, st, i - 1);
		quickAs(v, i + 1, dr);
	}
}
void quickDes(int v[],int st, int dr)
{
	if (st < dr)
	{
		//pivotul este inițial v[st]
		int m = (st + dr) / 2;
		int aux = v[st];
		v[st] = v[m];
		v[m] = aux;
		int i = st, j = dr, d = 0;
		while (i < j)
		{
			if (v[i] < v[j])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				d = 1 - d;
			}
			i += d;
			j -= 1 - d;
		}
		quickAs(v, st, i - 1);
		quickAs(v, i + 1, dr);
	}
}
void Sort::QuickSort(bool ascendent)
{
	if (ascendent)
		quickAs(this->vector,0, this->size - 1);
	else
		quickDes(this->vector,0, this->size - 1);
}

void Sort::BubbleSort(bool ascendent)
{
	int i = 0;
	bool ok;
	if (ascendent)
		do
		{
			ok = true;
			while (this->vector[i + 1])
			{
				if (this->vector[i] > this->vector[i + 1])
				{
					swap(this->vector[i], this->vector[i + 1]);
					ok = false;
				}
				i++;
			}
		} while (ok == false);
	else
		do
		{
			ok = true;
			while (this->vector[i + 1])
			{

				if (this->vector[i] < this->vector[i + 1])
				{
					swap(this->vector[i], this->vector[i + 1]);
						ok = false;
				}
				i++;
			}
		} while (ok == false);
}

void Sort::Print()
{
	int i=0;
	for(i=0;i<this->size;i++)
		cout << this->vector[i] << " ";
	cout << "\n";
}

int Sort::GetElementsCount()
{
	return this->size;
}

int Sort::GetElementFromIndex(int index)
{
	return this->vector[index];
}
