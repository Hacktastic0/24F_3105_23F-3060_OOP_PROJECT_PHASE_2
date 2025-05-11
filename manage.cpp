#include "manage.h"

manage::manage()
{
	count = 0;
	size = 2;
	players = new player[size];
    readFromFile();
}

void manage::resize()
{ 
	player* temp = new player[size];
	for (int i = 0; i < size; i++)
		temp[i] = players[i];
	size *= 2;
	delete[] players;
	players = new player[size];
	for (int i = 0; i < size / 2; i++)
		players[i] = temp[i];

}

void manage::insert(player p)
{
	if (count < size)
		players[count++] = p;
	else
	{
		resize();
		insert(p);
	}
}

void manage::saveToFile()
{
    ofstream outFile("kingdom_data.txt", ios::out);
    if (outFile.is_open()) 
    {       
        for (int i = 0; i < count; i++) 
        {
            outFile << players[i].name << endl;   
            outFile << players[i].s.money << endl;
            outFile << players[i].s.happines << endl;
            outFile << players[i].s.sizeP << endl;
            outFile << players[i].s.food << endl;
            outFile << players[i].s.tax << endl;
            outFile << players[i].s.amountFood << endl;
            outFile << players[i].s.foodConsumption << endl; 
            outFile << players[i].s.army.getSoldiers() << endl;
            outFile << players[i].s.economy.getInflation() << endl;
            int temp;     
            for (int j = 0; j < 3; j++)
            { 
                temp = players[i].s.arr[j]->getQ(); 
                outFile << temp << endl; 
            }
        }
        outFile.close();
        cout << "\nDATA SAVED SCUCESSFULLY !\n";
    }
    else
    { 
        cout << "UNABLE TO OPEN FILE WHILE SAVING DATA \n";
    }
}

void manage::readFromFile()
{ 
    ifstream inFile("kingdom_data.txt");
    if (inFile.is_open())
    {
        int soldiers;
        string leaderName; 
        float inflationRate; 
        player temp;
        while (!inFile.eof())
        {
            inFile >> temp.name;
            inFile >> temp.s.money;
            inFile >> temp.s.happines;
            inFile >> temp.s.sizeP;
            inFile >> temp.s.food;
            inFile >> temp.s.tax;
            inFile >> temp.s.amountFood;
            inFile >> temp.s.foodConsumption;
            inFile >> soldiers;
            inFile >> inflationRate;
            for (int i = 0; i < 3; i++)
            { 
                int tempa = 0;
                inFile >> tempa;
                temp.s.arr[i]->setQuantity(tempa);
            }
            delete[] temp.s.population;
            temp.s.population = new person[temp.s.sizeP];
             
            temp.s.army.setSoliders(soldiers);
            temp.s.economy.setInflation(inflationRate); 
            insert(temp);
        } 
        cout << "\DATA SUCESSFULLY LOADED !\n";
        inFile.close();
    } 
    else
    {
        cout << "FAILED TO OPEN FILE WHILE LOADING DATA !!! \n";
    }
}

void manage::StartGame()
{ 
    int choice; 
    player *p; 
    string name; 
    bool flag = true; 
    while (flag)
    {
        system("cls");
        cout << "1.ENTER A NEW PLAYER \n2.PLAY GAME \n3.EXIT \n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            p = new player();
            cout << "ENTER NAME OF PLAYER : ";
            cin >> name;
            p->setName(name);
            insert(*p);
            delete p;
            p = NULL; 
            break;
        case 2:
            cout << "ENTER YOUR PLAYER NAME : ";
            cin >> name;
            for (int i = 0; i < size; i++) 
                if (name == players[i].name)    
                {
                    players[i].play(players, size);
                    break;
                }
            break;
        case 3:
            flag = false; 
            saveToFile(); 
            break; 
        default:
            break;
        }
    }
}
