#pragma once

#include "ConcreteUnits.hpp"

class HeroCreator {    
public:
     Juggernaut* CreateJug();

     Sven* CreateSven();
};

class CreepCreator {
public:
    Centaur* CreateCentaur();
    
    Golem* CreateGolem();
};


