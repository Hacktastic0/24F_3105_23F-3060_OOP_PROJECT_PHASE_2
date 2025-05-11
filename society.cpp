#include "society.h"

Society::Society()
{
    arr[0] = new stone<int>();
    arr[1] = new iron<int>();
    arr[2] = new wood<int>();

    if (sizeP<= 0) //resetting the game 
    {
        sizeP = 10;
        population = new person[sizeP];
        food = 10;
        foodConsumption = sizeP;
        count = 0;
        tax = 2;
        money = 1000000;
        happines = 0;
        amountFood = foodConsumption;
    }
   

} 
 
void Society::resize() 
{
    int oldSize = sizeP; 
    person* temp = new person[oldSize];
    for (int i = 0; i < oldSize; i++)
        temp[i] = population[i];
    sizeP = (oldSize * 2) + 1;
    delete[] population;
    population = new person[sizeP];
    for (int i = 0; i < oldSize; i++)
        population[i] = temp[i];
    delete[] temp;
    foodSize();
}

void Society::consumefood()
{
    if (food > 0)
    {
        food -= foodConsumption; 
        if (happines <= 5) 
            happines += 1;
    }
    else
    {
        cout << "\nFOOD EXAUSTED !!!!!";
        if (happines >-6)
            happines -= 2;
    } 
}   

void Society::foodSize()
{ 
    foodConsumption = sizeP * 2;
}

void Society::getTax()
{
    if (tax == 0) 
    {  
        if (happines <= 10)
            happines += 2;
        return;
    }
    if (sizeP > 0)
    { 
        money += sizeP * tax *10  ;
      
    }
}

void Society::populationResize()
{
    int oldSize = sizeP;
    int newSize = sizeP + happines/2; 
    if (newSize <= 0)
        newSize = 1;
    person* temp = new person[oldSize];  
    for (int i = 0; i < oldSize; i++)
        temp[i] = population[i];
    delete[] population;
    sizeP = newSize;
    population = new person[sizeP];  
    for (int i = 0; i < oldSize && i < sizeP; i++)
        population[i] = temp[i]; 
    delete[] temp;
}

void Society::getFood()
{
    if (money>0)
    { 
        food += amountFood;
        money -= amountFood * 2;
    } 
    else
        cout << "\nNO MONEYYYYY!!!\n";
}

void Society::militaryActions()
{
   
    army.pay(money );
    army.desertion();
    money -= army.getSoldiers() * 1;
}

void Society::leadershipActions()
{
    leader.leadershipEffect(*this);
    leader.coup(*this); 
} 
 
void Society::economyActions() 
{ 
    economy.applyInflation(*this);
}

void Society::triggerRandomEvent()
{
    if (rand() % 10 < 2)
    {
        Event e; 
        e.trigger(*this);
    }
}

void Society::run()
{
    bool flag = true; 
    int count = 0; 
    char c;
    while (flag)
    {
        system("cls");
        for (int i = 0; i < 60; i++)
            cout << "=";
        cout << "\n\t\t\tKINGDOM STATUS\n";
        for (int i = 0; i < 60; i++)
            cout << "=";
        cout << "\n\n\tMONEY : " << money; 
        cout << "\n\tHAPPINESS : " << happines;
        cout << "\n\tPOPULATION : " << sizeP;
        cout << "\n\tFOOD : " << food;
        cout << "\n\tTAX RATE : " << tax;
        cout << "\n\tFOOD INTAKE PER TURN : " << amountFood; 
        cout << "\n\tFOOD CONSUMPTION RATE : " << foodConsumption; 
        cout << "\n\tARMY SIZE : " << army.getSoldiers();
        cout << "\n\tECONOMY INFLATION RATE : " << economy.getInflation()*10 << "%";
        cout << "\n\tRESOURCES : ";  
        for (int i = 0; i < 3; i++)
            arr[i]->Display();
        cout << "\n\nPress [T] to Increase Tax | [Y] to Decrease Tax";
        cout << "\nPress [U] to Increase Food Intake | [I] to Decrease Food Intake";
        cout << "\nPress [M] to Train Army\n";
        cout << "\nPress [F] to  do nothing\n";
        cout << "\nPress [R] to  get menu for resources\n";
        cout << "\nPress [E] to  Exit\n"; 
        cin >> c; 

        for (int i = 0; i < 60; i++)
            cout << "=";
        cout << "\n";
        if (happines > 10) 
            happines = 10;
        if (happines < -10)
            happines = -10; 
        count++;
        consumefood(); 
        getTax();
        populationResize();
        getFood(); 
        foodSize(); 
        militaryActions();
        if (count >= 10)
        {
            leadershipActions(); 
            count = 0;
        }
        economyActions();
        triggerRandomEvent();
       // input(flag); 
        in(c, flag);
        
        Sleep(700);
    }   
 
}
void Society::in(char c,bool &flag)
{
    if (c == 'T' || c == 't')
        if (tax < 5)
            tax++; 
    if (c == 'Y' || c == 'y')  
        if (tax > 0)
            tax--; 
    if (c == 'U' || c == 'u')
        amountFood+=5; 
    if (c == 'I' || c == 'i')
        amountFood -= 5;  
    if (c == 'e' || c == 'E')
        flag = false; 
    if (c == 'm' || c == 'M')
        army.train();
    if (c == 'r' || c == 'R')
        Resourcemenu(); 


}
void Society::input(bool &flag)
{
    if (_kbhit())
    {
        char c = _getch();
        switch (c)
        { 
        case 27 : 
            flag = false;
             
            break;
        case 't':
        case 'T': 
            if (tax < 5)
                tax++;
            break;
        case 'Y':
        case 'y':
            if (tax > 0 ) 
                tax--;
            break;
        case 'u':
        case 'U':
            amountFood+=5;
            break;
        case 'i': 
        case 'I':  
            amountFood-=5 ;
            break; 
        case 'm': 
        case 'M': 
            army.train();
            break; 
        } 
        c = ' ';
    }
}
#include <fstream> // include at top if not already


void Society::Resourcemenu()
{
    int choice; 
    cout << "1-BUY 3 IRON (PRICE : 50)\n2-BUY 5 STONE  (PRICE  :35)\n3-BUT 10 WOOD (PRICE : 20)\n"; 
    cin >> choice;
    choice--; 
    if (money>arr[choice]->getPrice())
    {
        arr[choice]->attain(); 
        money -= arr[choice]->getPrice();
         
    }
}
