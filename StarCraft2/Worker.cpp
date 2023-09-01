#include <iostream>
#include "Worker.hpp"
#include "Incubator.hpp"

const int Worker::resourceCost{1};

Worker::Worker() : Unit("Worker", 10), collectedResources(0)
{
}

Incubator Worker::BuildIncubator()
{
    return Incubator();
}

Barrack Worker::BuildBarrack()
{
    return Barrack();
}

void Worker::CollectResources(FactionResourcesManager& frm)
{
    int resources = GameResources::GetResourcesCollectedEachTime();
    GameResources::SubtractQuantity(resources);
    frm.AddResources(resources);
    collectedResources += resources;
}

int Worker::GetCollectedResources()
{
    return collectedResources;
}

int Worker::GetResourceCost() const
{
    return resourceCost;
}
