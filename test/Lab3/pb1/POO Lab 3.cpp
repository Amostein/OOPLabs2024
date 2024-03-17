// POO Lab 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
#include "Math.h"
using namespace std;
int main()
{
	Math mat;
	cout<<mat.Add(7, 12)<<" "<<mat.Add(7,12,3)<<"\n";
	cout << mat.Mul(7, 12) << " " << mat.Mul(7, 12, 3) << "\n";

	double d, e, f;
	d = 3.5;
	e = 5.2;
	f = 10.7;
	cout << mat.Add(d, e) << " " << mat.Add(d, e, f) << "\n";
	cout << mat.Mul(d, e) << " " << mat.Mul(d, e, f) << "\n";

	cout << mat.Add(6, 10, 8, 6, 4, 2, 1, 3) << '\n';
	cout<<mat.Add("23", "138");

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
