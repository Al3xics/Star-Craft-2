#include <iostream>
#include <random>
#include "Monster.hpp"

Monster::Monster(std::string name, int health, int damage) : name(name), health(health), damage(damage), isAlive(true)
{
}

int Monster::GetHealth()
{
    return health;
}

bool Monster::IsAlive()
{
    return isAlive;
}

void Monster::TakeDamage(int damageTaken)
{
    health -= damageTaken;
    if (health <= 0)
    {
        isAlive = false;
    }
}

void Monster::Attack(std::vector<Soldier>& soldiers)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    int size = static_cast<int>(soldiers.size());
    std::uniform_int_distribution<> dis(0, size - 1);
    int randomIndex = dis(gen);
    Soldier& soldierAttacked = soldiers[randomIndex];

    if (soldierAttacked.IsAlive())
    {
        soldierAttacked.TakeDamage(damage);
        std::cout << damage << " damage was done to a soldier." << std::endl;
        if (!soldierAttacked.IsAlive())
        {
            soldiers.erase(soldiers.begin() + randomIndex);
            std::cout << "A soldier is dead !" << std::endl;
        }
    }
}

void Monster::Attack(std::vector<Worker>& workers)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    int size = static_cast<int>(workers.size());
    std::uniform_int_distribution<> dis(0, size - 1);
    int randomIndex = dis(gen);
    Worker& workerAttacked = workers[randomIndex];

    if (workerAttacked.IsAlive())
    {
        workerAttacked.TakeDamage(damage);
        std::cout << damage << " damage was done to a worker." << std::endl;
        if (!workerAttacked.IsAlive())
        {
            workers.erase(workers.begin() + randomIndex);
            std::cout << "A worker is dead !" << std::endl;
        }
    }
}

void Monster::Attack(std::vector<Incubator>& incubators)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    int size = static_cast<int>(incubators.size());
    std::uniform_int_distribution<> dis(0, size - 1);
    int randomIndex = dis(gen);
    Incubator& incubatorAttacked = incubators[randomIndex];

    if (incubatorAttacked.IsNotDestroyed())
    {
        incubatorAttacked.TakeDamage(damage);
        std::cout << damage << " damage was done to an incubator." << std::endl;
        if (!incubatorAttacked.IsNotDestroyed())
        {
            incubators.erase(incubators.begin() + randomIndex);
            std::cout << "An incubator is destroyed !" << std::endl;
        }
    }
}
