#pragma once
#include "Car.h"
class Fiat :
    public Car
{
public:
    Fiat();
    float timp(int, int, bool&) override;
    const char* nume() override;
};

