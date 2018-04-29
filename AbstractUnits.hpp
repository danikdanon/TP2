#pragma once
#include <string>

// общий класс юнита - основа для героев и крипов
class Unit {
public:
    int healthPoints;
    int damage;
    virtual void info() {};
    virtual int getStrength() = 0;
    virtual void addUnit(Unit* p) {
        assert( false );
    }
    virtual void useBuff() {};
};

// abstract class hero
class Hero : public Unit {
public:
    std::string skill1;
    std::string skill2;
    int default_money;
    int mana;
    int level;
    double hp_coef;    // на сколько увеличивается хп, мана и дамаг за каждый уровень
    double mana_coef;
    double dmg_coef;
    
    void use_skill1() {};
    void use_skill2() {};
    void info() {};
    int getStrength(){
        return 0;
    };
    void useBuff() {};
};


// абстракный класс - нейтральный крип
class NeutralCreep : public Unit{
public:
    int spawn_time;
    int killing_reward;
    
    virtual int getStrength() = 0;
};

