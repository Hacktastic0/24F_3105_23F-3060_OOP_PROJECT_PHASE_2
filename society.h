#pragma once  
#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include <windows.h> 
#include "person.h"
#include "military.h"
#include "leader.h"
#include "economy.h"
#include "event.h"
#include "resource.h"
class Society
{
    long food;
    int foodConsumption;
    person* population;
    int sizeP; 
    int count;
    int amountFood; 
    Military army;
    Leader leader;
    Economy economy;
    int happines;
    int tax;
    int money;
    Resource<int>*arr[3];
public:
    Society();
    void resize();
    void consumefood();  
    void foodSize();
    void getTax();
    void populationResize();
    void getFood();
    void militaryActions();
    void leadershipActions();
    void economyActions();
    void triggerRandomEvent();
    void run();
    void input(bool&);
 
    void in(char ,bool&); 
    void Resourcemenu();
    friend class Leader; 
    friend class Event; 
    friend class Economy; 
    friend class player; 
    friend class manage;  
};