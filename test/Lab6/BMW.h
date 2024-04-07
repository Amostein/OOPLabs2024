#pragma once
#include "Car.h"
class BMW :
    public Car
{
public:
    BMW();
    float timp(int, int, bool&) override;
    const char* nume() override;
};

