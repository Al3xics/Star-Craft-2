#include <iostream>
#include "Resources.hpp"

int Resources::totalQuantity = 0;
int Resources::resourcesCollectedEachTime = 3;

Resources::Resources(int initialQuantity)
{
    totalQuantity = initialQuantity;
    std::cout << "========== There is a total of " << totalQuantity << " resources you can collect for the entire game ==========\n\n" << std::endl;
}

int Resources::GetQuantity()
{
    return totalQuantity;
}

int Resources::GetResourcesCollectedEachTime()
{
    return resourcesCollectedEachTime;
}

void Resources::AddQuantity(int amount)
{
    totalQuantity += amount;
}

void Resources::SubtractQuantity(int amount)
{
    totalQuantity = std::max(0, totalQuantity - amount);
}
