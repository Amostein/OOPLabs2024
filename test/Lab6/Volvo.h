#pragma once
#include "Car.h"
class Volvo :
    public Car
{
public:
    Volvo();
    float timp(int, int, bool&) override;
    const char* nume() override;
};

