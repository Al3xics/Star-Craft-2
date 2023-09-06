#pragma once
#include <string>
#include "Unit.hpp"
class Boss;

class Soldier : public Unit
{
private:
    static const int resourceCost;
    int damage;


public:
    Soldier();
    int GetResourceCost() const override;
    int GetDamage();
    void Attack(Boss& boss);
};

