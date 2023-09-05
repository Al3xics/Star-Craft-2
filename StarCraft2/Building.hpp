#pragma once
#include <string>
#include "FactionResourcesManager.hpp"

class Building
{
protected:
    std::string name;
    int health;
    bool isNotDestroyed;


public:
    Building(const std::string& name, int health);
    int GetHealth();
    bool IsNotDestroyed();
    void TakeDamage(int damageTaken);
    bool CanBuild(FactionResourcesManager& frm);
    virtual int GetResourceCost() const;
};

