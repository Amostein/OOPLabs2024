#include <iostream>
float operator"" _Kelvin(unsigned long long x)
{
    return x - 273.15;
}

float operator"" _Fahrenheit(unsigned long long x)
{
    float fr = x - 32;
    return fr / 1.8;
}
int main()
{
    float a = 300_Kelvin;
    float b = 150_Fahrenheit;
    std::cout << a << "\n";
    std::cout << b;
    return 0;
}
