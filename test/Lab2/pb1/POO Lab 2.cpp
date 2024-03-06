// POO Lab 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "NumberList.h"
using namespace std;
int main()
{
    NumberList vec;
    vec.Init();
    cout << "Cate numere: \n";
    int n,x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        vec.Add(x);
    }
    cout << "Vectorul nesortat: ";
    vec.Print();
    cout << "\nVectorul sortat: ";
    vec.Sort();
    vec.Print();
    return 0;
}
