#include "Creators.hpp"

Juggernaut* HeroCreator::CreateJug() {
    return new Juggernaut;
}

Sven* HeroCreator::CreateSven() {
    return new Sven;
}

Centaur* CreepCreator::CreateCentaur() {
    return new Centaur;
}

Golem* CreepCreator::CreateGolem() {
    return new Golem;
    }
