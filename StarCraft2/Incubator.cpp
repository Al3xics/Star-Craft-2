#include <iostream>
#include "Incubator.hpp"
#include "Worker.hpp"

const int Incubator::resourceCost{5};

Incubator::Incubator() : Building("Incubator")
{
}

Worker Incubator::CreateWorker()
{
    return Worker();
}

int Incubator::GetResourceCost() const
{
    return resourceCost;
}
