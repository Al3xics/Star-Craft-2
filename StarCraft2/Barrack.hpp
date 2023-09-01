#pragma once
#include <string>
#include <vector>
#include "Building.hpp"
#include "Unit.hpp"
#include "Soldier.hpp"

class Barrack : public Building
{
private:
    static const int resourceCost;


public:
    Barrack();
    Soldier CreateSoldier();
    int GetResourceCost() const override;
};

