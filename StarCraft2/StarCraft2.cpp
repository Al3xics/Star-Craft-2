#include <chrono>
#include <iostream>
#include <string>
#include <thread>

#include "Barrack.hpp"
#include "Boss.hpp"
#include "Building.hpp"
#include "FactionResourcesManager.hpp"
#include "GameResources.hpp"
#include "Incubator.hpp"
#include "Monster.hpp"
#include "Soldier.hpp"
#include "Unit.hpp"
#include "Worker.hpp"

int main()
{
    // Instructions
    std::cout << "===================================================================================================================\n";
    std::cout << "\tAction you can do if you have enough resources :\n";
    std::cout << "\t\t'incubator' will create an incubator\n";
    std::cout << "\t\t'barrack' will create a barrack\n";
    std::cout << "\t\t'worker' will create a worker\n";
    std::cout << "\t\t'soldier' will create a soldier\n";
    std::cout << "\t\t'collect' will make one or more worker collect resources\n";
    std::cout << "\t\n";
    std::cout << "\tYou can chose a number of time to repeat your previous action :\n";
    std::cout << "\t\t' ' chose a number\n";
    std::cout << "\t\n";
    std::cout << "\tAt the end of each turn, each of the soldiers you have, will do 3 damage to the Boss.\n";
    std::cout << "\tThe Boss also recovers 10 HP each turn.\n";
    std::cout << "\tHe will also attack yours soldiers, if there si, if not, your workers, if not, your incubators.\n";
    std::cout << "\t\n";
    std::cout << "\tYour goal is to take down the boss ! Good luck !\n";
    std::cout << "===================================================================================================================\n" << std::endl;

    

    // Initialize start of the game
    std::vector<Incubator> incubators;
    std::vector<Barrack> barracks;
    std::vector<Worker> workers;
    std::vector<Soldier> soldiers;
    GameResources resources(30);
    FactionResourcesManager FRM;
    Incubator incubator;
    incubators.push_back(incubator);
    for (int i = 0; i < 3; ++i)
    {
        Worker worker = Worker();
        workers.push_back(worker);
    }
    Boss boss = Boss();



    // Game Start
    while (boss.GetHealth() > 0)
    {
        std::cout << "\n\n\n===================================================================================================================" << std::endl;
        // Total resources remaining in the game
        std::cout << "Total resources remaining to be collected : " << GameResources::GetQuantity() << std::endl;
        // Number of resources
        std::cout << "Remaining resources: " << FRM.GetTotalCollectedResources() << std::endl;
        // Health of the Boss
        std::cout << "Health of the Boss : " << boss.GetHealth() << std::endl;
        // Number of buildings and unit created
        std::cout << "You currently have :";
        std::cout << "\n\tIncubator : " << incubators.size();
        std::cout << "\n\tBarrack : " << barracks.size();
        std::cout << "\n\tWorker : " << workers.size();
        std::cout << "\n\tSoldier : " << soldiers.size() << "\n\n" << std::endl;



        if (incubators.empty())
        {
            std::cout << "You have lost.\nAll your soldiers, workers and incubators were killed/destroyed.\nTry again !" << std::endl;
            std::cout << "===================================================================================================================" << std::endl;
            break;
        }



        std::string action;
        int number;
        std::string input;
        std::cout << "Enter your action : ";
        std::cin >> action;


        if (action == "incubator")
        {
            if (!workers.empty())
            {
                while (true)
                {
                    try
                    {
                        std::cout << "Number : ";
                        std::cin >> input;
                        number = std::stoi(input);
                        std::cout << std::endl;
                        break;
                    }
                    catch (const std::invalid_argument&)
                    {
                        std::cout << "Invalid input. Please enter a valid integer." << std::endl;
                    }
                }

                Worker& lastWorker = workers.back();
                std::vector<Incubator> newIncubators = lastWorker.BuildIncubator(number, FRM);

                if (!newIncubators.empty())
                {
                    incubators.insert(incubators.end(), newIncubators.begin(), newIncubators.end());
                    std::cout << newIncubators.size() << " " << action << "(s) created !" << std::endl;
                }
            }
            else
            {
                std::cout << "No workers available. Please create a worker." << std::endl;
            }
        }
        else if (action == "barrack")
        {
            if (!workers.empty())
            {
                while (true)
                {
                    try
                    {
                        std::cout << "Number : ";
                        std::cin >> input;
                        number = std::stoi(input);
                        std::cout << std::endl;
                        break;
                    }
                    catch (const std::invalid_argument&)
                    {
                        std::cout << "Invalid input. Please enter a valid integer." << std::endl;
                    }
                }

                Worker& lastWorker = workers.back();
                std::vector<Barrack> newBarracks = lastWorker.BuildBarracks(number, FRM);

                if (!newBarracks.empty())
                {
                    barracks.insert(barracks.end(), newBarracks.begin(), newBarracks.end());
                    std::cout << newBarracks.size() << " " << action << "(s) created !" << std::endl;
                }
            }
            else
            {
                std::cout << "No workers available. Please create a worker." << std::endl;
            }
        }
        else if (action == "worker")
        {
            if (!incubators.empty())
            {
                while (true)
                {
                    try
                    {
                        std::cout << "Number : ";
                        std::cin >> input;
                        number = std::stoi(input);
                        std::cout << std::endl;
                        break;
                    }
                    catch (const std::invalid_argument&)
                    {
                        std::cout << "Invalid input. Please enter a valid integer." << std::endl;
                    }
                }

                Incubator& lastIncubator = incubators.back();
                std::vector<Worker> newWorkers = lastIncubator.CreateWorkers(number, FRM);

                if (!newWorkers.empty())
                {
                    workers.insert(workers.end(), newWorkers.begin(), newWorkers.end());
                    std::cout << newWorkers.size() << " " << action << "(s) created !" << std::endl;
                }
            }
            else
            {
                std::cout << "No incubators available. Please create an incubator." << std::endl;
            }
        }
        else if (action == "soldier")
        {
            if (!barracks.empty())
            {
                while (true)
                {
                    try
                    {
                        std::cout << "Number : ";
                        std::cin >> input;
                        number = std::stoi(input);
                        std::cout << std::endl;
                        break;
                    }
                    catch (const std::invalid_argument&)
                    {
                        std::cout << "Invalid input. Please enter a valid integer." << std::endl;
                    }
                }

                Barrack& lastBarrack = barracks.back();
                std::vector<Soldier> newSoldiers = lastBarrack.CreateSoldiers(number, FRM);

                if (!newSoldiers.empty())
                {
                    soldiers.insert(soldiers.end(), newSoldiers.begin(), newSoldiers.end());
                    std::cout << newSoldiers.size() << " " << action << "(s) created !" << std::endl;
                }
            }
            else
            {
                std::cout << "No barracks available. Please create a barrack." << std::endl;
            }
        }
        else if (action == "collect")
        {
            if (!workers.empty())
            {
                if (resources.GetQuantity() > 0)
                {
                    std::cout << "3 resources are collected per worker.\n";
                    std::cout << "How many workers should collect resources ?\n";

                    while (true)
                    {
                        try
                        {
                            std::cout << "Number : ";
                            std::cin >> input;
                            number = std::stoi(input);
                            std::cout << std::endl;
                            break;
                        }
                        catch (const std::invalid_argument&)
                        {
                            std::cout << "Invalid input. Please enter a valid integer." << std::endl;
                        }
                    }

                    int workerCount = static_cast<int>(workers.size());
                    int min = std::min(number, workerCount);
                    std::string message;
                    for (int i = 0; i < min; ++i)
                    {
                        if (resources.GetQuantity() > 0)
                        {
                            workers[i].CollectResources(FRM);
                        }
                        else
                        {
                            message = "No more resources to collect.";
                            break;
                        }
                    }

                    std::cout << "Resources collected !" << std::endl;
                    if (!message.empty())
                    {
                        std::cout << message << std::endl;
                    }
                }
                else
                {
                    std::cout << "Threre is no more resources to collect." << std::endl;
                }
            }
            else
            {
                std::cout << "No workers available. Please create a worker." << std::endl;
            }
        }
        else
        {
            std::cout << "Invalid action. Try again." << std::endl;
            std::cout << "===================================================================================================================" << std::endl;
            continue;
        }



        if (!soldiers.empty())
        {
            int soldierCount = static_cast<int>(soldiers.size());
            int damageDoneToTheBoss{0};
            for (int i = 0; i < soldierCount; ++i)
            {
                if (boss.IsAlive())
                {
                    soldiers[i].Attack(boss);
                    damageDoneToTheBoss += soldiers[i].GetDamage();
                }
                else
                {
                    break;
                }
            }
            std::cout << damageDoneToTheBoss << " damage was done to the Boss." << std::endl;
        }



        if (boss.IsAlive())
        {
            if (!soldiers.empty())
            {
                boss.Attack(soldiers);
            }
            else if (!workers.empty())
            {
                boss.Attack(workers);
            }
            else if (!incubators.empty())
            {
                boss.Attack(incubators);
            }

            boss.RecoverHealth(10);
        }

        

        std::cout << "===================================================================================================================\n\n" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    }

    
    if (boss.GetHealth() <= 0)
    {
        std::cout << "You have defeated the boss !!!\nCongratulations !!!" << std::endl;
    }
    
}