#include "Building.hpp"

Building::Building(const std::string& name) : name(name)
{
}

bool Building::CanBuild(FactionResourcesManager& frm)
{
    int cost = GetResourceCost();
    return frm.GetTotalCollectedResources() >= cost;
}

int Building::GetResourceCost() const
{
    return 1;
}
