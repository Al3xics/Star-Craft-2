#pragma once
#include <string>
#include "FactionResourcesManager.hpp"

class Unit
{
protected:
    std::string name;
    int health;
    bool isAlive;


public:
    Unit(const std::string& name, int health);
    int GetHealth();
    bool IsAlive();
    void TakeDamage(int damageTaken);
    bool CanCreate(FactionResourcesManager& frm);
    virtual int GetResourceCost() const;
};

