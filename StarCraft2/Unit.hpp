#pragma once
#include <string>
#include "FactionResourcesManager.hpp"

class Unit
{
protected:
    std::string name;
    int health;


public:
    Unit(const std::string& name, int health);
    bool CanCreate(FactionResourcesManager& frm);
    virtual int GetResourceCost() const;
};

