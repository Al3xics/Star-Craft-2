#include <iostream>
#include "Soldier.hpp"
#include "Boss.hpp"

const int Soldier::resourceCost{2};

Soldier::Soldier() : Unit("Soldier", 20), damage(3)
{
}

int Soldier::GetResourceCost() const
{
    return resourceCost;
}

int Soldier::GetDamage()
{
    return damage;
}

void Soldier::Attack(Boss& boss)
{
    if (boss.IsAlive())
    {
        boss.TakeDamage(damage);
        if (!boss.IsAlive())
        {
            std::cout << "The Boss is dead !" << std::endl;
        }
    }
}
