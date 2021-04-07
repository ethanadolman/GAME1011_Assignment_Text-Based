#include "Room.h"

void Room::CreateRoom(char Direction, string Description)
{
	

	switch(Direction)
	{
	case 'N':
	case 'n':
		if(North == nullptr)
		North = new Room(Description);
		break;
	case 'E':
	case 'e':
		if (East == nullptr)
			East = new Room(Description);
		break;
	case 'S':
	case 's':
		if (South == nullptr)
			South = new Room(Description);
		break;
	case 'W':
	case 'w':
		if (West == nullptr)
			West = new Room(Description);
		break;
	}
}


Room* Room::GetRoom(char Direction)
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

string Room::GetDescription()
{
	//return description
	return;
}

void Room::SetDescription(string Description)
{
	//set description
}
