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
    
    virtual int getStrength() {
        int total = 0;
        for(int i=0; i<v.size(); ++i)
            total += v[i]->getStrength();
        return total;
    }
    
    virtual void addUnit(Unit* p) {
        v.push_back(p);
    }
    
    virtual void info(){
        cout << "Attack = " << attack << endl;
        cout << "Gold = " << gold << endl;
        cout << "wood = " << wood << endl;
        cout << "dist = " << dist << endl;
        cout << "hp = " << hp << endl;
        
        for (auto unit: v){
            unit->info();
        }
    }
    
    virtual void SetAttack(){
        attack = getStrength();
    }
    
    virtual void MakeCreep(string name){
        if (name == "Golem" && wood > 10){
            wood-=10;
            addUnit(new Golem);
        }
        if (name == "Centaur" && wood > 15){
            wood-=15;
            addUnit(new Centaur);
        }
    }
    
    virtual bool Farm(){
        wood += 1;
        gold += 10;
        dist += 5;
        attack += 5;
        return true;
    }
    
    virtual bool Follow(){   // returns true if we can follow enemy
        if (dist > 10){
            dist -= 10;
            return true;
        }
        else
            return false;
    }
    
    virtual bool Retreat(){
        if (dist > 10){
            dist -= 10;
            return true;
        }
        else
            return false;
    }
    
    virtual bool Attack(){
        if (attack >= 10){
            attack -= 10;
            return true;
        }
        else
            return false;
    }
    
    virtual void add(string name){
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


// proxy example
class TeamProxy : public Team{
public:
    Team* inner;
    
    
    TeamProxy(Team* t){
        inner = t;
    }
    
    virtual int getStrength() {
        cout << "method getStrength called" << endl;
        return inner->getStrength();
    }
    
    virtual void addUnit(Unit* p) {
        cout << "method addUnit called" << endl;
        inner->addUnit(p);
    }
    
    virtual void info(){
        cout << "method info called" << endl;
        inner->info();
    }
    
    virtual void SetAttack(){
        cout << "method SetAttack called" << endl;
        return inner->SetAttack();
    }
    
    virtual void MakeCreep(string name){
        cout << "method MakeCreep called" << endl;
        inner->MakeCreep(name);
    }
    
    virtual bool Farm(){
        cout << "method Farm called" << endl;
        return inner->Farm();
    }
    
    virtual bool Follow(){   // returns true if we can follow enemy
        cout << "method Follow called" << endl;
        return inner->Follow();
    }
    
    virtual bool Retreat(){
        cout << "method Retreat called" << endl;
        return inner->Retreat();
    }
    
    virtual bool Attack(){
        cout << "method Attack called" << endl;
        return inner->Attack();
    }
    
    virtual void add(string name){
        cout << "method add called" << endl;
        inner->add(name);
    }
};

