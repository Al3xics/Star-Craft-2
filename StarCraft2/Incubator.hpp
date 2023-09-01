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
    Worker CreateWorker();
    int GetResourceCost() const override;
};

