#include <iostream>
#include "Barrack.hpp"

const int Barrack::resourceCost{4};

Barrack::Barrack() : Building("Barrack")
{
}

Soldier Barrack::CreateSoldier()
{
    return Soldier();
}

int Barrack::GetResourceCost() const
{
    return resourceCost;
}
