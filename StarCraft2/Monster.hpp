#pragma once
#include <string>
#include <vector>
#include "Soldier.hpp"
#include "Worker.hpp"
#include "Incubator.hpp"

class Monster
{
protected:
    std::string name;
    int health;
    int damage;
    bool isAlive;


public:
    Monster(std::string name, int health, int damage);
    int GetHealth();
    int GetDamage();
    bool IsAlive();
    void DoDamage(std::vector<Soldier>& soldiers);
    void DoDamage(std::vector<Worker>& workers);
    void DoDamage(std::vector<Incubator>& incubators);
};

