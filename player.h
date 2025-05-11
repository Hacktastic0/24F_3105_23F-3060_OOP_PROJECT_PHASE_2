#pragma once  
#include "society.h" 
class player
{
	Society s;   
	string name; 
public : 
	void setName(string); 
	void play(player arr[], int);
	void attack(player& p);  
	void ShareResource(player& p);  
	friend class manage;
}; 