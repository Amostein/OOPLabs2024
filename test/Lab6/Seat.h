#pragma once
#include "Car.h"
class Seat :
    public Car
{
public:
    Seat();
    float timp(int, int, bool&) override;
    const char* nume() override;
};

