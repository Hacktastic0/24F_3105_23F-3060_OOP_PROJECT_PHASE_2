#include "military.h"
#include "society.h"
Military::Military()
{
    soldiers = 100;
    morale = 50;
    salary = 5;
}

void Military::train()
{

    soldiers += soldiers / 10;
    morale += 2;  
    cout << "\nTRAINING SOLIDERS .... \n";  
    Sleep(4000);
}

void Military::pay(int &m)
{
    m -= soldiers * 2;
} 

void Military::desertion()
{
    int deserters = (100 - morale) * soldiers / 1000;
    soldiers -= deserters; 
}
 
int Military::getSoldiers()
{
    return soldiers;
}

void Military::setSoliders(int number)
{
    soldiers = number;
}

int Military::getSoliders()
{
    return soldiers;
}
