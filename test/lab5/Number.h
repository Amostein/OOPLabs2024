#pragma once
class Number
{
	// add data members
	char* val;
	int baza;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	~Number();

	// add operators and copy/move constructor
	Number(Number& m);
	Number(const char* s);
	Number(int x);
	Number()
	{
		val = nullptr;
		baza = 0;
	}
	
	friend Number operator + (Number& nr1, Number& nr2);
	friend Number operator - (Number& nr1, Number& nr2);
	char* operator +=(Number& nr);
	char* operator =(Number& nr);
	char operator [](int i);
	bool operator <(Number& nr);
	bool operator >(Number& nr);
	bool operator >=(Number& nr);
	bool operator <=(Number& nr);
	bool operator ==(Number& nr);

	//add the following operators: addition, subtraction, index operator, relation operators (> , < , >= , <=, ==, etc)

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};

