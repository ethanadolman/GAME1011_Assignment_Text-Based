#include "Room.h"

void Room::CreateRoom(char Direction, string Description)
{
	

	switch(Direction)
	{
	case 'N':
	case 'n':
		if (North == nullptr)
		{
			North = new Room(Description);
			this->GetNeighbourRoom('n')->SetNeighbourRoom('s', this);
		}
		break;
	case 'E':
	case 'e':
		if (East == nullptr)
		{
			East = new Room(Description);
			this->GetNeighbourRoom('e')->SetNeighbourRoom('w', this);
		}
		break;
	case 'S':
	case 's':
		if (South == nullptr)
		{
			South = new Room(Description);
			this->GetNeighbourRoom('s')->SetNeighbourRoom('n', this);
		}
		break;
	case 'W':
	case 'w':
		if (West == nullptr)
		{
			West = new Room(Description);
			this->GetNeighbourRoom('w')->SetNeighbourRoom('e', this);
		}
		break;
	}
}


Room* Room::GetNeighbourRoom(char Direction)
{
	switch (Direction)
	{
	case 'N':
	case 'n':
		return North;
		break;
	case 'E':
	case 'e':
		return East;
		break;
	case 'S':
	case 's':
		return South;
		break;
	case 'W':
	case 'w':
		return West;
		break;
	}
}


void Room::SetNeighbourRoom(char Direction, Room* room)
{
	switch (Direction)
	{
	case 'N':
	case 'n':
		North = room;
		break;
	case 'E':
	case 'e':
		East = room;
		break;
	case 'S':
	case 's':
		South = room;
		break;
	case 'W':
	case 'w':
		West = room;
		break;
	}
}


string Room::GetDescription()
{
	return m_Description;
}


void Room::SetDescription(string Description)
{
	m_Description = Description;
}

string Room::ListSearchables(int i)
{
	if (i < Searchables.size())
	{
		if (Searchables[i]->Searched == false)
		{
			return " " + Searchables[i]->name + ListSearchables(i+1);
		}
			return ListSearchables(i+1);
	}
	return "\n";
	
}

Item* Room::Search(string Name)
{
	for (unsigned i = 0; i < Searchables.size(); i++)
	{
		if (Searchables[i]->name == Name && Searchables[i]->Searched == false)
		{
			Searchables[i]->Searched = true;
			cout << "You obtained a " << Searchables[i]->item->Name << endl;
			return Searchables[i]->item;
		}
	}
	cout << "\aERROR: Searchable does not exist or has already been searched" << endl;
	return nullptr;
}


