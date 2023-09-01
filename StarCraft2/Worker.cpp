#include <iostream>
#include "Worker.hpp"
#include "Incubator.hpp"

const int Worker::resourceCost{1};

Worker::Worker() : Unit("Worker", 10), collectedResources(0)
{
}

std::vector<Incubator> Worker::BuildIncubator(int amount, FactionResourcesManager& frm)
{
    std::vector<Incubator> incubators;
    for (int i = 0; i < amount; ++i)
    {
        Incubator incubator = Incubator();
        if (incubator.CanBuild(frm))
        {
            frm.SubtractResources(incubator.GetResourceCost());
            incubators.push_back(incubator);
        }
        else
        {
            std::cout << "You don't have enough resources to build " << amount << " incubator(s). Collect some resources." << std::endl;
            break;
        }
    }
    return incubators;
}

std::vector<Barrack> Worker::BuildBarracks(int amount, FactionResourcesManager& frm)
{
    std::vector<Barrack> barracks;
    for (int i = 0; i < amount; ++i)
    {
        Barrack barrack = Barrack();
        if (barrack.CanBuild(frm))
        {
            frm.SubtractResources(barrack.GetResourceCost());
            barracks.push_back(barrack);
        }
        else
        {
            std::cout << "You don't have enough resources to build " << amount << " barrack(s). Collect some resources." << std::endl;
            break;
        }
    }
    return barracks;
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
