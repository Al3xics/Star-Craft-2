#pragma once
#include <string>

class Resources
{
private:
	static int totalQuantity;
	static int resourcesCollectedEachTime;

public:
	Resources(int initialQuantity);
	static int GetQuantity();
	static int GetResourcesCollectedEachTime();
	static void AddQuantity(int amount);
	static void SubtractQuantity(int amount);
};

