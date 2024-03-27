#pragma once
class Sort
{
    // add data members
    int* vector;
    int size;
public:
    // add constuctors
    ~Sort();
    Sort(int nrElemente, int min, int max);
    Sort(int* vector, int nrElemente);
    Sort(const char* valori);
    Sort(int nrArgumente, ...);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};

