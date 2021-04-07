#pragma once
#include <iostream>
#include <string> 
using namespace std;

class Room
{
public:
	Room(string Description = "")
	{
		//set desctiption
	}
	void CreateRoom(char Direction, string Description = "");
	Room* GetRoom(char Direction);
	string GetDescription();
	void SetDescription(string Description);
private:
	string m_Description;
	Room* North = nullptr;
	Room* East = nullptr;
	Room* South = nullptr;
	Room* West = nullptr;
};

