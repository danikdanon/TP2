#pragma once
#include <iostream>
#include "GameState.hpp"

using namespace std;

class Base
{
    Base *next;  // указатель на следующий элемент в цепочке
public:
    Base()
    {
        next = 0;
    }
    void setNext(Base *n)
    {
        next = n;
    }
    void add(Base *n)
    {
        if (next)
            next->add(n);
        else
            next = n;
    }
    
    // передаем запрос следующему объекту
    virtual void handle(int i)
    {
        next->handle(i);
    }
};

class WeatherChanger: public Base
{
public:
    virtual void handle(int i)
    {
        if (rand() % 3)
        {
            // 3. 3 из 4 запросов не обрабатываем
            cout << "H1 passsed " << i << "  ";
            // 3. и делегируем базовому классу
            Base::handle(i);        }
        else
            cout << "H1 handled " << i << "  ";
    }
};

class Handler2: public Base
{
public:
    /*virtual*/void handle(int i)
    {
        if (rand() % 3)
        {
            cout << "H2 passsed " << i << "  ";
            Base::handle(i);
        }
        else
            cout << "H2 handled " << i << "  ";
    }
};

class Handler3: public Base
{
public:
    /*virtual*/void handle(int i)
    {
        if (rand() % 3)
        {
            cout << "H3 passsed " << i << "  ";
            Base::handle(i);
        }
        else
            cout << "H3 handled " << i << "  ";
    }
};
