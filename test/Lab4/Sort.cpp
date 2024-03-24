#include "Sort.h"
#include <iostream>

using namespace std;
Sort::Sort()
{
	int n,x,i;
	cout << "Nr de elemente: ";
	cin >> n;
	this->size = n;
	cout << "\nDati elementele vectorului: ";
	for (i = 0; i < n; i++);
	{
		cin >> x; 
		this->vector[i] = x;
	}
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
