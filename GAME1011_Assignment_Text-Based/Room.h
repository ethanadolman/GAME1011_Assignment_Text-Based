#pragma once
#include <iostream>
#include <string> 
using namespace std;

class Room
{
	Room(string Description = "")
	{
		//set desctiption
	}
public:
	void CreateRoom(char Direction, string Description = "");
	Room* GetRoom(char Direction);
	string GetDescription();
	void SetDescription(string Description);
private:
	Room* North = nullptr;
	Room* East = nullptr;
	Room* South = nullptr;
	Room* West = nullptr;
};

