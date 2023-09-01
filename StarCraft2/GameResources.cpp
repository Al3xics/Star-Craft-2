#include <iostream>
#include "GameResources.hpp"

int GameResources::totalQuantity = 0;
int GameResources::resourcesCollectedEachTime = 3;

GameResources::GameResources(int initialQuantity)
{
    totalQuantity = initialQuantity;
    std::cout << "========== There is a total of " << totalQuantity << " resources you can collect for the entire game ==========\n\n" << std::endl;
}

int GameResources::GetQuantity()
{
    return totalQuantity;
}

int GameResources::GetResourcesCollectedEachTime()
{
    return resourcesCollectedEachTime;
}

void GameResources::AddQuantity(int amount)
{
    totalQuantity += amount;
}

void GameResources::SubtractQuantity(int amount)
{
    totalQuantity = std::max(0, totalQuantity - amount);
}
