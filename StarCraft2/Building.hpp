#pragma once
#include <string>
#include "FactionResourcesManager.hpp"

class Building
{
protected:
    std::string name;


public:
    Building(const std::string& name);
    bool CanBuild(FactionResourcesManager& frm);
    virtual int GetResourceCost() const;
};

