#include "DireTeam.hpp"

void DireTeam::AddHero(std::string name) {
    if( name == "Juggernaut" ) {
        Heroes.push_back(Hcreator.CreateJug());
    }
    if( name == "Sven" ) {
        Heroes.push_back(Hcreator.CreateSven());
    }
}

void DireTeam::AddCreep(std::string name) {
    if( name == "Golem" ) {
        Creeps.push_back(Ccreator.CreateGolem());
    }
    if( name == "Centanaur" ) {
        Creeps.push_back(Ccreator.CreateCentaur());
    }
}

void DireTeam::info() {
    std::cout << "Команда Dire состоит из : " << std::endl;
    for (auto  &hero : Heroes)
        hero->info();
    for (auto  &creep : Creeps)
        creep->info();
}

int DireTeam::getStrength() {
    int ans = 0;
    for (auto &hero: Heroes)
        ans += hero->getStrength();
    for (auto & creep: Creeps)
        ans += creep->getStrength();
    return ans;
}
