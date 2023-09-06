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
    bool IsAlive();
    void TakeDamage(int damageTaken);
    void Attack(std::vector<Soldier>& soldiers);
    void Attack(std::vector<Worker>& workers);
    void Attack(std::vector<Incubator>& incubators);
};

