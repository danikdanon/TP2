#pragma once
#include <iostream>
#include "AbstractUnits.hpp"

using namespace std;


class wrapper : public Hero {
public:
    Hero* inner;
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
        cout << "Necro called" << endl;
    }
};

class AttackBuff : public wrapper{
public:
    AttackBuff(Hero* hero) : wrapper(hero) {};
    void useBuff(){
        wrapper::useBuff();
        cout << "AttackBuffed" << endl;
    }
};

 
