#include <iostream>
#include "Soldier.hpp"

const int Soldier::resourceCost{2};

Soldier::Soldier() : Unit("Soldier", 20)
{
}

int Soldier::GetResourceCost() const
{
    return resourceCost;
}
