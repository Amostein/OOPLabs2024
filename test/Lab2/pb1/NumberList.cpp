#include "NumberList.h"
#include <iostream>
void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
	if(this->count>=10)
		return false;
	this->numbers[this->count] = x;
	this->count++;
}

void NumberList::Sort()
{
	int aux;
	bool ok;
	do
	{
		ok = true;
		for(int i=0;i<this->count-1;i++)
			if (this->numbers[i] > this->numbers[i + 1])
			{
				aux = this->numbers[i];
				this->numbers[i] = this->numbers[i + 1];
				this->numbers[i + 1] = aux;
				ok = false;
			}
				
	} while (ok == false);
}

void NumberList::Print()
{
	int i;
	for (i = 0; i < this->count; i++)
		std::cout << this->numbers[i] << " ";
}


