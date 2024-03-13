#include "Student.h"
#include <cstring>

void Student::setName(char s[])
{
	strcpy(this->Name, s);
}

void Student::setMaths(float x)
{
	if(x>=1.0f and x<=10.0f)
		this->Maths = x;
}

void Student::setEnglish(float x)
{
	if (x >= 1.0f and x <= 10.0f)
		this->English = x;
}

void Student::setHistory(float x)
{
	if (x >= 1.0f and x <= 10.0f)
		this->History = x;
}

char* Student::getName()
{
	return this->Name;
}

float Student::getMaths()
{
	return this->Maths;
}

float Student::getEnglish()
{
	return this->English;
}

float Student::getHistory()
{
	return this->History;
}

float Student::getAvg()
{
	float avg;
	avg = (this->Maths + this->English + this->History) / 3;
	return avg;
}

int Student::compareName(Student x, Student y)
{
	return 0;
}

int Student::compareMaths(Student x, Student y)
{
	float xGrade = x.getMaths();
	float yGrade = y.getMaths();
	if (xGrade > yGrade)
		return 1;
	if (xGrade == yGrade)
		return 0;
	return -1;
}

int Student::compareEnglish(Student x, Student y)
{
	float xGrade = x.getEnglish();
	float yGrade = y.getEnglish();
	if (xGrade > yGrade)
		return 1;
	if (xGrade == yGrade)
		return 0;
	return -1;
}

int Student::compareHistory(Student x, Student y)
{
	float xGrade = x.getHistory();
	float yGrade = y.getHistory();
	if (xGrade > yGrade)
		return 1;
	if (xGrade == yGrade)
		return 0;
	return -1;
}

int Student::compareAvg(Student x, Student y)
{
	float xGrade = x.getAvg();
	float yGrade = y.getAvg();
	if (xGrade > yGrade)
		return 1;
	if (xGrade == yGrade)
		return 0;
	return -1;
}
