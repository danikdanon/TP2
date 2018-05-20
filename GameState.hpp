#pragma once
#include <iostream>

using namespace std;

class GameState{
    int time;
    string weather;
    int distance;
    
public:
    void SetTime(int t){
        time = t;
    }
    
    int GetTime(){
        return time;
    }
    
    void SetWeather(string NewWeather){
        weather = NewWeather;
    }
    
    string GetWeather(){
        return weather;
    }
    
    void SetDistance(int dist){
        distance = dist;
    }
    
    int GetDistance(){
        return distance;
    }
};
