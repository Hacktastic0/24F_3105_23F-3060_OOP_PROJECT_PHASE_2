#pragma once 
#include "player.h" 
#include <fstream>
class manage
{

	player* players;  
	int size;
	int count; 
public: 
	manage();
	
	void resize();
	void insert(player p);
	void saveToFile(); 
	void readFromFile(); 
	void StartGame(); 
	
};
