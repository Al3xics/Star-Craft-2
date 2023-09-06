#pragma once
#include <string>
#include "Unit.hpp"
#include "Barrack.hpp"
#include "FactionResourcesManager.hpp"
#include "GameResources.hpp"
class Incubator;

class Worker : public Unit
{
private:
	int collectedResources;
	static const int resourceCost;


public:
	Worker();
	std::vector<Incubator> BuildIncubator(int amount, FactionResourcesManager& frm);
	std::vector<Barrack> BuildBarracks(int amount, FactionResourcesManager& frm);
	void CollectResources(FactionResourcesManager& frm);
	int GetCollectedResources();
	int GetResourceCost() const override;
};

