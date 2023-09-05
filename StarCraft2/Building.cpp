#include <stdexcept>
#include "Building.hpp"

Building::Building(const std::string& name, int health) : name(name), health(health), isNotDestroyed(true)
{
}

int Building::GetHealth()
{
    return health;
}

bool Building::IsNotDestroyed()
{
    return isNotDestroyed;
}

void Building::TakeDamage(int damageTaken)
{
    health -= damageTaken;
    if (health <= 0)
    {
        isNotDestroyed = false;
    }
}

bool Building::CanBuild(FactionResourcesManager& frm)
{
    int cost = GetResourceCost();
    return frm.GetTotalCollectedResources() >= cost;
}

int Building::GetResourceCost() const
{
    throw std::runtime_error("You cannot use the 'Building' class method : 'GetResourceCost()'.");
}
