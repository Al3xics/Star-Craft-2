#include <random>
#include "Boss.hpp"

const int Boss::MaximumTotalHealth{100};

Boss::Boss() : Monster("Boss", MaximumTotalHealth, 10)
{
}

void Boss::RecoverHealth(int amount)
{
    health += amount;
    if (health > MaximumTotalHealth)
    {
        health = MaximumTotalHealth;
    }
}
