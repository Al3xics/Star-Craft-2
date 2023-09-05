#pragma once
#include "Monster.hpp"

class Boss : public Monster
{
private:
    static const int MaximumTotalHealth;


public:
    Boss();
    void RecoverHealth(int amount);
};

