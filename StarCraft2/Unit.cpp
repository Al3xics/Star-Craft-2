#include "Unit.hpp"

Unit::Unit(const std::string& name, int health) : name(name), health(health)
{
}

bool Unit::CanCreate(FactionResourcesManager& frm)
{
    int cost = GetResourceCost();
    return frm.GetTotalCollectedResources() >= cost;
}

int Unit::GetResourceCost() const
{
    return 1;
}
