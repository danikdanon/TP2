//
//  main.cpp
//  TP2
//
//  Created by Даниил on 29.04.2018.
//  Copyright © 2018 Даниил. All rights reserved.
//

#include "main.hpp"
#include <iostream>
#include "TeamCreator.hpp"
#include "ConcreteUnits.hpp"
#include "AbstractUnits.hpp"
#include "Upgrade.hpp"

using namespace std;

void printInstruction(){
    cout << "На каждом шаге выберите одно из следующий действий:/n -Follow -Retreat -Farm -Attack, вы можете аттаковать, если дистанция между командами равна 0" << endl;
}

void DoAction(string action,Team &team, Team &oppositeTeam, int& dist){
    if (action == "Follow")
        if (team.Follow())
            dist -= 10;
    if (action == "Retreat")
        if (team.Retreat())
            dist += 10;
    if (action == "Attack")
        if (team.Attack() && dist == 0){
            oppositeTeam.hp -= 10;
        }
    if (action == "Farm"){
        team.Farm();
    }
}


int main(){
    int countOfMoves = 5;// количество ходов
    string RadiantHero;
    string DireHero;
    Team radiant;
    Team dire;
    
    cout << "Выберите героя, команда Radiant" << endl;
    cin >> RadiantHero;
    radiant.add(RadiantHero);
    cout << "Выберите 4 крипов" << endl;
    for (int i = 0; i < 4; i++) // выборка 4 крипов в армию
    {
        string creep;
        cin >> creep;
        radiant.add(creep);
    }
    
    
    cout << "Выберите героя, команда Dire" << endl;
    cin >> DireHero;
    dire.add(DireHero);
    cout << "Выберите 4 крипов" << endl;
    for (int i = 0; i < 4; i++) // выборка 4 крипов в армию
    {
        string creep;
        cin >> creep;
        dire.add(creep);
    }
    
    printInstruction();
    int currDist = 10; // начальные параметры
    radiant.dist = 40;
    dire.dist = 45;
    dire.hp = 50;
    radiant.hp = 40;
    radiant.attack = 10;
    dire.attack = 10;
    for (int i = 0; i < countOfMoves; i++){
        string RadiantAction;
        string DireAction;
        cout << "Radiant info::" << endl;
        radiant.info();
        cout << "Current distanse between teams " << currDist << endl;
        cin >> RadiantAction;
        DoAction(RadiantAction, radiant, dire, currDist);
        cout << "Dire info::" << endl;
        dire.info();
        cout << "Current distanse between teams " << currDist << endl;
        cin >> DireAction;
        DoAction(DireAction, dire, radiant, currDist);
    }
    
    if (radiant.hp > dire.hp)
        cout << "RadiantWin" << endl;
    else
        cout << "DireWin" << endl;
    return 0;
}
