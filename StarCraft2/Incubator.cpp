#include <iostream>
#include "Incubator.hpp"
#include "Worker.hpp"

const int Incubator::resourceCost{5};

Incubator::Incubator() : Building("Incubator", 10)
{
}

std::vector<Worker> Incubator::CreateWorkers(int amount, FactionResourcesManager& frm)
{
    std::vector<Worker> workers;
    for (int i = 0; i < amount; ++i)
    {
        Worker worker = Worker();
        if (worker.CanCreate(frm))
        {
            frm.SubtractResources(worker.GetResourceCost());
            workers.push_back(worker);
        }
        else
        {
            std::cout << "You don't have enough resources to create " << amount << " worker(s). Collect some resources." << std::endl;
            break;
        }
    }
    return workers;
}

int Incubator::GetResourceCost() const
{
    return resourceCost;
}
