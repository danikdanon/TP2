#pragma once
#include "Creators.hpp"
#include <iostream>
#include <vector>
#include <string>

class DireTeam {
public:
    DireTeam() = default;
    ~DireTeam() = default;
    
    void AddHero(std::string name);
    void AddCreep(std::string name);
    void info();
    int getStrength();
    
private:
    std::vector<Hero*> Heroes;
    std::vector<NeutralCreep*> Creeps;
    CreepCreator Ccreator;
    HeroCreator Hcreator;
};

