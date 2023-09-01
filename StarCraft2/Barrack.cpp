#include <iostream>
#include "Barrack.hpp"

const int Barrack::resourceCost{4};

Barrack::Barrack() : Building("Barrack")
{
}

std::vector<Soldier> Barrack::CreateSoldiers(int amount, FactionResourcesManager& frm)
{
    std::vector<Soldier> soldiers;
    for (int i = 0; i < amount; ++i)
    {
        Soldier soldier = Soldier();
        if (soldier.CanCreate(frm))
        {
            frm.SubtractResources(soldier.GetResourceCost());
            soldiers.push_back(soldier);
        }
        else
        {
            std::cout << "You don't have enough resources to create " << amount << " soldier(s). Collect some resources." << std::endl;
            break;
        }
    }
    return soldiers;
}

int Barrack::GetResourceCost() const
{
    return resourceCost;
}
