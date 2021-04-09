#pragma once
#include <iostream>
#include <string> 
#include <vector>
#include "TextManager.h"
using namespace std;

struct Item
{
	string Name;
	Item(string Name)
	{
		this->Name = Name;
	}
};

class Room
{
public:

	Room(string Description = "", bool Locked = false)
	{
		m_Description = Description;
		this->Locked = Locked;
	}
	struct Searchable
	{
		string name;
		Item* item;
		bool Searched = false;
		Searchable(string Name, Item* Item = nullptr)
		{
			name = Name;
			item = Item;
		}
	};
	void CreateRoom(char Direction, string Description, bool Locked = false);

	Room* GetNeighbourRoom(char Direction);
	void SetNeighbourRoom(char Direction, Room* room);
	string GetDescription();
	void SetDescription(string Description);
	bool isLocked() { return Locked; };
	void Unlock() { Locked = false; };
	void AddSearchable(string Name, Item* item = nullptr) { Searchables.push_back(new Searchable(Name, item)); };
	string ListSearchables(int i = 0);
	Item* Search(string Name);
	//	void AddSearchable(string Name, string Item = NULL) { new Searchable(Name, Item); };
	
private:

	string m_Description;
	Room* North = nullptr;
	Room* East = nullptr;
	Room* South = nullptr;
	Room* West = nullptr;
	vector<Searchable*> Searchables;
	bool Locked;
};

