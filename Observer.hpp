#include <stdio.h>
#include "AbstractUnits.hpp"
#include "ConcreteUnits.hpp"
#include <vector>
#pragma once

using namespace std;

class Observer{
public:
    virtual void update(int value) = 0;
};

class HeroObserver : public Observer{
public:
    Hero* inner;
    int strategy;
    
    HeroObserver(Hero* hero) {
        inner = hero;
    }
    
    void update(int value) {
        strategy = value;
    }
};

class CreepObserver : public Observer{
public:
    NeutralCreep* inner;
    int strategy;
    
    CreepObserver(NeutralCreep* creep){
        inner = creep;
    }
    
    void update(int value){
        strategy = value;
    }
};

class UnitObserver : public Observer{
public:
    Unit* inner;
    int strategy;
    
    UnitObserver(Unit* unit){
        inner = unit;
    }
    
    void update(int value){
        strategy = value;
    }
};

class Subject{
public:
    vector<Observer*> UpdateList;
    int value;
    
    void add(Observer* obs) {
        UpdateList.push_back(obs);
    }
    
    void update() {
        for (auto elem: UpdateList)
            elem->update(value);
    }
    
    void SetValue( int val ){
        value = val;
        update();
    }
};
