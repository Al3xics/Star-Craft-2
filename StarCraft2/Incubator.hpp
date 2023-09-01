#pragma once
#include <string>
#include <vector>
#include "Building.hpp"
class Worker;

class Incubator : public Building
{
private:
    static const int resourceCost;


public:
    Incubator();
    std::vector<Worker> CreateWorkers(int amount, FactionResourcesManager& frm);
    int GetResourceCost() const override;
};

