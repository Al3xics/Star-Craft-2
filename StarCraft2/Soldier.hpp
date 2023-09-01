#pragma once
#include <string>
#include "Unit.hpp"

class Soldier : public Unit
{
private:
    static const int resourceCost;


public:
    Soldier();
    int GetResourceCost() const override;
};

