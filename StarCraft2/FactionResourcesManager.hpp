#pragma once
#include <string>

class FactionResourcesManager
{
private:
	int totalCollectedResources;

public:
	FactionResourcesManager();
	void AddResources(int amount);
	void SubtractResources(int amount);
	int GetTotalCollectedResources();
};

