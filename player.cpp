#include "player.h"

void player::setName(string s)
{ 
	name = s; 
}

void player::play(player arr[], int size)
{
	int choice; 
	system("cls"); 
	cout << "1.MANAGE KINGDOM\n2.ATTACK PLAYER \n3.SHARE RESOURCES \n4.EXIT\n"; 
	cin >> choice;   
	switch (choice) 
	{
	case 1:  
		s.run();  
		break; 
	case 2 : 
		for (int i = 0; i < size; i++)
		{
			if (arr[i].name != name)
				cout << i + 1 << ") " << arr[i].name << endl;
		}
		cout << "ENTER ID OF PLAYER TO ATTACK : "; 
		cin >> choice; 
		choice--;   
		attack(arr[choice]); 
		break; 
	case 3:  
		for (int i = 0; i < size; i++)
		{
			if (arr[i].name != name)
				cout << i + 1 << ") " << arr[i].name << endl;
		}
		cout << "ENTER ID OF PLAYER YOU WANT TO SHARE RESOURCES WITH : ";
		cin >> choice;
		choice--;
		ShareResource(arr[choice]);
	default:
		break;
	}

}

void player::attack(player& p)
{ 

	s.army.setSoliders(-1 * p.s.army.getSoldiers());
	p.s.army.setSoliders(-1 * s.army.getSoldiers());
	if (s.army.getSoldiers() < 0) //we lost the battle 
	{
		p.s.money += s.money; 
		s.money = 0;  
		s.population -= p.s.army.getSoldiers() * 3; //each solider will kill 2 civilians 
	}
	if (p.s.army.getSoldiers() < 0) //opponent lost the battle 
	{
		s.money += p.s.money;  
		p.s.money = 0;  
		p.s.population -= p.s.army.getSoldiers()*3 ; 
	}
}

void player::ShareResource(player& p)
{ 
	int choice; 
	int amount; 
	cout << "WHAT DO YOU WANT TO SHARE : \n"; 
	cout << "1.STONE\n2.IRON \n3.WOOD \n"; 
	cin >> choice;  
	cout << "HOW MUCH DO YOU WANT TO SHARE : "; 
	cin >> amount; 
	p.s.arr[choice]->incrementQuantity(amount);
	s.arr[choice]->incrementQuantity(-amount);
}

