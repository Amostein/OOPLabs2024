
#include <iostream>
#include "Student.h"

using namespace std;

int main()
{
	Student lista[20];
	int n;
	char nume[50];
	cout << "Nr de studenti: ";
	cin >> n;
	cout << "\n";
	float m, e, h;
	for (int i = 1; i <= n; i++)
	{
		cin.getline(nume, 50);
		cout << "Nota mate: ";
		cin >> m;
		cout << "\nNota English: ";
		cin >> e;
		cout << "\nNota History: ";
		cin >> h;
		cout << "\n";
		lista[i].setName(nume);
		lista[i].setMaths(m);
		lista[i].setEnglish(e);
		lista[i].setHistory(h);
	}
}
