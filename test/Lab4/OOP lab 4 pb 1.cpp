// OOP lab 4 pb 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Sort.h"
using namespace std;
int main()
{
    Sort s1(10, 1, 100);
    Sort s2(new int[5] {420, 7, 3, 10, 1}, 5);
    Sort s3("10,40,100,5,70");
    Sort s4(7, 10, 84, 15, 6, 74, 40, 165);
    printf("Elementele initiale ale lui s1: ");
    s1.Print();
    s1.InsertSort();
    printf("Elementele dupa sortarea descrescator elementelor din s1: ");
    s1.Print();
    printf("Elementele initiale ale lui s2: ");
    s2.Print();
    s2.BubbleSort();
    printf("Elementele dupa sortarea crescator elementelor din s2: ");
    s2.Print();
    printf("Elementele initiale ale lui s3: ");
    s3.Print();
    s3.QuickSort();
    printf("Elementele dupa sortarea descrescator elementelor din s3: ");
    s3.Print();
    printf("Elementele initiale ale lui s4: ");
    s4.Print();
    s4.BubbleSort();
    printf("Elementele dupa sortarea crescator elementelor din s4: ");
    s4.Print();
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
