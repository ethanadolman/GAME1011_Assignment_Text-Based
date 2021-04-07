#pragma once
#include <iostream>
#include <string> 
#include "TextManager.h"
using namespace std;

class Room
{
public:

	Room(string Description = "")
	{
		m_Description = Description;
	}

	void CreateRoom(char Direction, string Description);

	Room* GetNeighbourRoom(char Direction);
	void SetNeighbourRoom(char Direction, Room* room);

	string GetDescription();
	void SetDescription(string Description);

private:

	string m_Description;
	Room* North = nullptr;
	Room* East = nullptr;
	Room* South = nullptr;
	Room* West = nullptr;
};

