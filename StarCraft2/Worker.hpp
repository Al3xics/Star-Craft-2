#pragma once
#include <string>
#include "Unit.hpp"
#include "Barrack.hpp"
#include "GameResources.hpp"
#include "FactionResourcesManager.hpp"
class Incubator;

class Worker : public Unit
{
private:
	int collectedResources;
	static const int resourceCost;


public:
	Worker();
	Incubator BuildIncubator();
	Barrack BuildBarrack();
	void CollectResources(FactionResourcesManager& frm);
	int GetCollectedResources();
	int GetResourceCost() const override;
};

