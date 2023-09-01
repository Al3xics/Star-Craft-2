#include "FactionResourcesManager.hpp"

FactionResourcesManager::FactionResourcesManager() : totalCollectedResources(20)
{
}

void FactionResourcesManager::AddResources(int amount)
{
    totalCollectedResources += amount;
}

void FactionResourcesManager::SubtractResources(int amount)
{
    totalCollectedResources = std::max(0, totalCollectedResources - amount);
}

int FactionResourcesManager::GetTotalCollectedResources()
{
    return totalCollectedResources;
}
