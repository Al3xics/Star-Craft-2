#pragma once
#include <string>

class GameResources
{
private:
	static int totalQuantity;
	static int resourcesCollectedEachTime;

public:
	GameResources(int initialQuantity);
	static int GetQuantity();
	static int GetResourcesCollectedEachTime();
	static void AddQuantity(int amount);
	static void SubtractQuantity(int amount);
};

