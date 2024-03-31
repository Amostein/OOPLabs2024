#include "Number.h"
#include <iostream>
using namespace std;
Number::Number(const char* value, int base)
{
	baza = base;
	val = new char(strlen(value) + 1);
	memcpy(val, value, strlen(value) + 1);
}

Number::~Number()
{
	delete val;
	val = nullptr;
}

Number::Number(Number& m)
{
	baza = m.baza;
	val = nullptr;
	val = m.val;
}

Number::Number(const char* sir)
{
	baza = 0;
	int i = 0;
	while (sir[i])
	{
		if ((int)(sir[i] - '0') > baza)
		{
			baza = (int)(sir[i] - '0');
		}
	}
	cout << val;
}

Number::Number(int x)
{
	baza = 10;
	char nr[100];
	if (x == 0)
		nr[0] = 0;
	else
	{
		nr[0] = '\0';
		int i = 0;
		while (x)
		{
			nr[i] = (char)((x % 10) + '0');
			x /= 10;
			i++;
		}
		nr[i] = '\0';
		int len = strlen(nr);
		for (int i = 0; i < len / 2; i++)
		{
			char aux = nr[i];
			nr[i] = nr[i + len - 1];
			nr[i + len - 1] = aux;
		}
	}
	val = nr;
}

void peDos(char* numar)
{
	int lung = strlen(numar);
	for (int i = 0; i < lung / 2; i++)
	{
		char aux = numar[i];
		numar[i] = numar[lung - i - 1];
		numar[lung - i - 1] = aux;
	}
}

int cifint(char c)
{
	if (c >= '0' and c <= '9')
		return (int)c - '0';
	else
		return (int)c - 'A' + 10;
}

char cifchar(int nr)
{
	if (nr <= 0 and nr >= 9)
		return (char)(nr + '0');
	else
		return (char)(nr - 10 + 'A');
}
void Number::SwitchBase(int newBase)
{
	//1578= 1000x1 + 100x5 + 10x7 + 1x8
	char nr[100];
	strcat_s(nr, val);
	int lung = strlen(nr);
	int pw = 1, num = 0, i;
	for (i = lung - 1; i >= 0; i--)
	{
		num += cifint(nr[i]) * pw;
		pw = pw * baza;
	}
	int rest, k;
	char aux[100];
	while (num != 0)
	{
		rest = num % newBase;
		num /= newBase;
		if (rest <= 9)
			aux[k++] = (char)(rest + '0');
		else
			aux[k++] = (char)(rest % 10 + 'A');
	}
	peDos(aux);
	delete[] val;
	val = new char[strlen(aux) + 1];
	strcpy_s(val, strlen(aux), aux);
	baza = newBase;
}

void Number::Print()
{
	for (int i = 0; i < GetDigitsCount(); i++)
		cout << val[i];
}

int Number::GetDigitsCount()
{
	return strlen(val);
}

int Number::GetBase()
{
	return this->baza;
}

int baza10(char* term, int base)
{
	char copie[100];
	copie[0] = '\0';
	strcat_s(copie, term);
	int lung = strlen(copie), pw = 1, nr = 0,i;
	for (i = lung - 1; i >= 0; i--)
	{
		nr += cifint(copie[i]) * pw;
		pw = pw * base;
	}
	return nr;
}
char chbaza10(int nr, int base)
{
	int p = 1, rest, k = 0;
	char aux[100];
	aux[0] = '\0';
	while (nr != 0)
	{
		rest = nr % base;
		nr /= base;
		if (rest <= 9)
		{
			aux[k++] = (char)(rest + '0');
		}
		else
		{
			aux[k++] = (char)(rest % 10 + 'A');
		}
		p *= 10;
	}
	peDos(aux);
	return aux;
}
Number operator +(Number& nr1, Number& nr2)
{
	Number sum;
	if (nr1.baza < nr2.baza)
		sum.baza = nr2.baza;
	else
		sum.baza = nr1.baza;
	int nr1 = baza10(nr1.val, nr1.baza);
	int nr2 = baza10(nr2.val, nr2.baza);
	int auxsum = nr1 + nr2;
	sum.val = chbaza10(auxsum, nr1.baza);
	return sum;
}

Number operator-(Number& nr1, Number& nr2)
{
	Number dif;
	if (nr1.baza < nr2.baza)
		dif.baza = nr2.baza;
	else
		dif.baza = nr1.baza;
	int nr1 = baza10(nr1.val, nr1.baza);
	int nr2 = baza10(nr2.val, nr2.baza);
	int auxdif = nr1 - nr2;
	dif.val = chbaza10(auxdif, nr1.baza);
	return dif;
}

char* Number::operator+=(Number& nr)
{
	int nr1 = baza10(val, baza);
	int nr2 = baza10(nr.val, nr.baza);
	nr1 = nr1 + nr2;
	if (baza < nr.baza)
		baza = nr.baza;
	val = chbaza10(nr1, baza);
	return val;
}

char* Number::operator=(Number& nr)
{
	baza = nr.baza;
	val = nr.val;
	return val;
}

char Number::operator[](int i)
{
	return val[i];
}

bool Number::operator<(Number& nr)
{
	int nr1 = baza10(val, baza);
	int nr2 = baza10(nr.val, nr.baza);
	return nr1<nr2;
}

bool Number::operator>(Number& nr)
{
	int nr1 = baza10(val, baza);
	int nr2 = baza10(nr.val, nr.baza);
	return nr1 > nr2;
}

bool Number::operator>=(Number& nr)
{
	int nr1 = baza10(val, baza);
	int nr2 = baza10(nr.val, nr.baza);
	return nr1 >= nr2;
}

bool Number::operator<=(Number& nr)
{
	int nr1 = baza10(val, baza);
	int nr2 = baza10(nr.val, nr.baza);
	return nr1 <= nr2;
}

bool Number::operator==(Number& nr)
{
	int nr1 = baza10(val, baza);
	int nr2 = baza10(nr.val, nr.baza);
	return nr1 == nr2;
}
