#include "Math.h"
#include <string.h>
#include <stdarg.h>
#include <iostream>
using namespace std;
int Math::Add(int a, int b)
{
    return a+b;
}

int Math::Add(int a, int b, int c)
{
    return a+b+c;
}

int Math::Add(double a, double b)
{
    return (int)a+b;
}

int Math::Add(double a, double b, double c)
{
    return (int)a+b+c;
}

int Math::Mul(int a, int b)
{
    return a*b;
}

int Math::Mul(int a, int b, int c)
{
    return a*b*c;
}

int Math::Mul(double a, double b)
{
    return (int)a*b;
}

int Math::Mul(double a, double b, double c)
{
    return (int)a*b*c;
}

int Math::Add(int count, ...)
{
    int sum = 0;
    va_list vl;
    va_start(vl, count);
    for (int i = 0; i < count; i++) 
        sum = sum + va_arg(vl, int);
    va_end(vl);
    return sum;
}

char* Math::Add(const char* a, const char* b)
{
    int sum,carry,x1,x2;
    int l1, l2;
    int Lmax;
    l1 = strlen(a);
    l2 = strlen(b);
    Lmax = max(l1, l2);
    char* Aux = new char[Lmax + 1];
    if(a==nullptr || b == nullptr)
        return nullptr;
    else
    {

        int cifra1, cifra2;
        x1 = l1 - 1;
        x2 = l2 - 1;
        carry = 0;
        int y = 0;
        while (x1 > -1 and x2 > -1)
        {
            cifra1 = a[x1] - '0';
            cifra2 = b[x2] - '0';
            sum = cifra1 + cifra2 + carry;
            carry = sum / 10;
            Aux[y++] = '0' + (sum % 10);
            x1--;
            x2--;
        }
        if (x1 > -1)
        {
            while (x1 > -1)
            {
                cifra1 = a[x1] - '0';
                sum = cifra1 + carry;
                carry = sum / 10;
                Aux[y++] = '0' + (sum % 10);
                x1--;
            }
        }
        else
        {
            while (x2 > -1)
            {
                cifra2 = a[x2] - '0';
                sum = cifra2 + carry;
                carry = sum / 10;
                Aux[y++] = '0' + (sum % 10);
                x2--;
            }
        }
        if (carry == 1)
            Aux[y++] = 1;
        for (int i = 0; i < y / 2; i++)
        {
            char auxx = Aux[i];
            Aux[i] = Aux[y - i - 1];
            Aux[y - i - 1] = auxx;
        }
    }
    return Aux;
}
