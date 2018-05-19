#pragma once
#include <iostream>
#include "AbstractUnits.hpp"

using namespace std;


class wrapper : public Hero {
public:
    Hero* inner;
    wrapper* next;
    wrapper(Hero* hero){
        inner = hero;
    }
    void useBuff(){
        inner->useBuff();
    };
};

class NecronomiconBuff : public wrapper{
public:
    NecronomiconBuff(Hero* hero) : wrapper(hero) {};
    void useBuff(){
        wrapper::useBuff();
        wrapper::mana-=20;
        cout << "Necro called" << endl;
    }
};

class AttackBuff : public wrapper{
public:
    AttackBuff(Hero* hero) : wrapper(hero) {};
    void useBuff(){
        wrapper::useBuff();
        wrapper::mana-=10;
        cout << "AttackBuffed" << endl;
    }
};

class Base : public wrapper{
    void useBuffs(){
        while (inner->mana >= 20){
            inner = new NecronomiconBuff( inner );
        }
        while (mana >= 10){
            inner = new AttackBuff ( inner );
        }
    }
};

 
