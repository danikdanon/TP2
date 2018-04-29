#pragma once
#include "AbstractUnits.hpp"
#include "ConcreteUnits.hpp"
#include <vector>

using namespace std;

class Team {
public:
    vector<Unit*> v;
    int dist;
    int attack;
    int wood;
    int gold;
    int hp;
    
    int getStrength() {
        int total = 0;
        for(int i=0; i<v.size(); ++i)
            total += v[i]->getStrength();
        return total;
    }
    
    void addUnit(Unit* p) {
        v.push_back(p);
    }
    
    void info(){
        cout << "Attack = " << attack << endl;
        cout << "Gold = " << gold << endl;
        cout << "wood = " << wood << endl;
        cout << "dist = " << dist << endl;
        cout << "hp = " << hp << endl;
        
        for (auto unit: v){
            unit->info();
        }
    }
    
    void SetAttack(){
        attack = getStrength();
    }
    
    void MakeCreep(string name){
        if (name == "Golem" && wood > 10){
            wood-=10;
            addUnit(new Golem);
        }
        if (name == "Centaur" && wood > 15){
            wood-=15;
            addUnit(new Centaur);
        }
    }
    
    bool Farm(){
        wood += 1;
        gold += 10;
        dist += 5;
        attack += 5;
        return true;
    }
    
    bool Follow(){   // returns true if we can follow enemy
        if (dist > 10){
            dist -= 10;
            return true;
        }
        else
            return false;
    }
    
    bool Retreat(){
        if (dist > 10){
            dist -= 10;
            return true;
        }
        else
            return false;
    }
    
    bool Attack(){
        if (attack >= 10){
            attack -= 10;
            return true;
        }
        else
            return false;
    }
    
    void add(string name){
        if (name == "Golem")
            addUnit(new Golem);
        if (name == "Sven")
            addUnit(new Sven);
        if (name == "Juggernaut")
            addUnit(new Juggernaut);
        if (name == "Centaur")
            addUnit(new Centaur);
    }
};

