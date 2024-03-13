#pragma once
class Student
{
public:
	char Name[50];
	float Maths;
	float English;
	float History;
	
	void setName(char s[]);
	void setMaths(float x);
	void setEnglish(float x);
	void setHistory(float x);

	char* getName();
	float getMaths();
	float getEnglish();
	float getHistory();
	float getAvg();

	int compareName(Student x, Student y);
	int compareMaths(Student x, Student y);
	int compareEnglish(Student x, Student y);
	int compareHistory(Student x, Student y);
	int compareAvg(Student x, Student y);

};

