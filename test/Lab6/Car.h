#pragma once
class Car
{
protected:
	int fCap;
	int fCons;
	int speed[3];
	const char* brand;
public:
	virtual float timp(int, int, bool&)=0;
	virtual const char* nume() = 0;
};

