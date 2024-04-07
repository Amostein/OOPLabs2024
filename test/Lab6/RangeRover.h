#pragma once
#include "Car.h"
class RangeRover :
    public Car
{
public:
    RangeRover();
    float timp(int, int, bool&) override;
    const char* nume() override;
};

