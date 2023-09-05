#include <stdexcept>
#include "Unit.hpp"

Unit::Unit(const std::string& name, int health) : name(name), health(health), isAlive(true)
{
}

int Unit::GetHealth()
{
    return health;
}

bool Unit::IsAlive()
{
    return isAlive;
}

void Unit::TakeDamage(int damageTaken)
{
    health -= damageTaken;
    if (health <= 0)
    {
        isAlive = false;
    }
}

bool Unit::CanCreate(FactionResourcesManager& frm)
{
    int cost = GetResourceCost();
    return frm.GetTotalCollectedResources() >= cost;
}

int Unit::GetResourceCost() const
{
    throw std::runtime_error("You cannot use the 'Unit' class method : 'GetResourceCost()'.");
}
