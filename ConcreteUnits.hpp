#pragma once
#include "AbstractUnits.hpp"
#include <iostream>

class Juggernaut : public Hero{     // герой Juggernaut
public:
    std::string skill1 = "Omnislash";
    std::string skill2 = "HealingWard";

    Juggernaut() {
        healthPoints = 600;
        damage = 60;
        mana = 300;
        level = 1;
        hp_coef = 1.2;
        mana_coef = 1.3;
        default_money = 650;
    }
    
    virtual void info() {
        std::cout << "hero = Juggernaut" << std:: endl;
    }
    
    virtual int getStrength(){
        return healthPoints + damage*4 + mana + level*20;
    }
};

class Sven : public Hero{     // герой Sven
    std::string skill1 = "Stormhammer";
    std::string skill2 = "Rage";
    
public:
    Sven() {
        healthPoints = 650;
        damage = 70;
        mana = 200;
        level = 1;
        hp_coef = 1.1;
        mana_coef = 1.2;
        default_money = 650;
    }
    
    virtual void info() {
        std::cout << "hero = Sven" << std:: endl;
    }
    
    virtual int getStrength(){
        return healthPoints + damage*4 + mana + level*20;
    }
};

class Centaur : public NeutralCreep{   // нейтральный крип - кентавр
public:
    Centaur() {
        healthPoints = 100;
        killing_reward = 120;
        spawn_time = 0;
        damage = 50;
    }
    virtual void info() {
        std::cout << "creep = centanaur" << std:: endl;
    }
    
    virtual int getStrength(){
        return 20;
    }
};

class Golem : public NeutralCreep{  // нейтральный крип - голем
public:
    Golem() {
        healthPoints = 50;
        killing_reward = 30;
        damage = 10;
        spawn_time = 0;
    }
    
    virtual void info() {
        std::cout << "creep = Golem" << std:: endl;
    }
    
    virtual int getStrength(){
        return 15;
    }
};
