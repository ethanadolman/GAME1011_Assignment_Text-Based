#include <iostream>
#include "Room.h"
#include "TextManager.h"
#include "DynRoomStack.h"
using namespace std;

int main()
{
	system("color F");
	// Create Text Arrays
	TextManager* Dialogue = new TextManager();

	DynRoomStack* StackOfRooms = new DynRoomStack();

	// Create First room
	Room* CurrentRoom = new Room(Dialogue->getDescription(0));

	CurrentRoom->CreateRoom('s', Dialogue->getDescription(1)); //room with cave note in drawer

	CurrentRoom->GetNeighbourRoom('s')->CreateRoom('e', Dialogue->getDescription(2)); // 3 man riddle

	CurrentRoom->GetNeighbourRoom('s')->CreateRoom('w', Dialogue->getDescription(3)); //bedroom

	CurrentRoom->CreateRoom('n', Dialogue->getDescription(4)); // locked room (cave)

	CurrentRoom->CreateRoom('e', Dialogue->getDescription(5)); //infinite loop room


	vector<Item*> Inventory;
	

	CurrentRoom->GetNeighbourRoom('s')->AddSearchable("Drawer", new Item("Note"));
	CurrentRoom->GetNeighbourRoom('s')->GetNeighbourRoom('w')->AddSearchable("Closet");
	CurrentRoom->GetNeighbourRoom('s')->GetNeighbourRoom('w')->AddSearchable("Drawer");
	CurrentRoom->GetNeighbourRoom('s')->GetNeighbourRoom('w')->AddSearchable("Bag", new Item("Key"));
	CurrentRoom->GetNeighbourRoom('s')->GetNeighbourRoom('w')->AddSearchable("Purse");
	CurrentRoom->GetNeighbourRoom('s')->GetNeighbourRoom('w')->AddSearchable("Cabinet");


	string action, object;
	do {
		system("cls");
		cout << CurrentRoom->GetDescription() << endl;
		cout << "Searchables:";
		cout << CurrentRoom->ListSearchables();

		cout << "Available Paths: ";
		if (CurrentRoom->GetNeighbourRoom('n') != nullptr)
			cout << "North ";
		if (CurrentRoom->GetNeighbourRoom('e') != nullptr)
			cout << "East ";
		if (CurrentRoom->GetNeighbourRoom('s') != nullptr)
			cout << "South ";
		if (CurrentRoom->GetNeighbourRoom('w') != nullptr)
			cout << "West ";
		cout << endl;
	cin >> action >> object;
	system("cls");
	if (action == "go" || action == "Go" || action == "move" || action == "Move")
	{
		if (object == "n" || object == "N" || object == "north" || object == "North")
		{
			if (CurrentRoom->GetNeighbourRoom('n') != nullptr)
				CurrentRoom = CurrentRoom->GetNeighbourRoom('n');
			else
			{
				cout << "\aERROR: Invalid Room\n";
				system("pause");
			}
		}

		else if (object == "e" || object == "E" || object == "east" || object == "East")
		{
			if (CurrentRoom->GetNeighbourRoom('e') != nullptr)
				CurrentRoom = CurrentRoom->GetNeighbourRoom('e');
			else
			{
				cout << "\aERROR: Invalid Room\n";
				system("pause");
			}
		}
		else if (object == "s" || object == "S" || object == "south" || object == "South")
		{
			if (CurrentRoom->GetNeighbourRoom('s') != nullptr)
				CurrentRoom = CurrentRoom->GetNeighbourRoom('s');
			else
			{
				cout << "\aERROR: Invalid Room\n";
				system("pause");
			}
		}
		else if (object == "w" || object == "W" || object == "west" || object == "West")
		{
			if (CurrentRoom->GetNeighbourRoom('w') != nullptr)
				CurrentRoom = CurrentRoom->GetNeighbourRoom('w');
			else
			{
				cout << "\aERROR: Invalid Room\n";
				system("pause");
			}
		}
		
		

	}
	else if (action == "use" || action == "Use")
	{
		bool ObjFound = false;
		for (unsigned i = 0; i < Inventory.size(); i++)
		{
			
				if (object == "key" || object == "Key")
				{
					ObjFound = true;
					break;
				}
				if (object == "note" || object == "Note")
				{
					cout << "The note Reads: \n";
						cout << "1. left follows after right\n2. you always begin with a left\n3. 1. is only becomes true after going left at least once\n4. the first two directions are the same\n5. 2. is false\n6. the third direction is opposite to direction you began with\n7. your first left should follow with a right";
						ObjFound = true;
						break;
				}
		}
		if (ObjFound == false)
		{
			cout << "\aERROR: Invalid Item\n";
		}
		system("pause");
	}
	else if (action == "search" || action == "Search" || action == "Look" || action == "look")
	{
		Item* item = CurrentRoom->Search(object);
		if (item != nullptr || item != NULL)
			Inventory.push_back(item);
		system("pause");
	}
	else {
		cout << CurrentRoom->GetDescription() << endl;
		cout << "Searchables:";
		cout << CurrentRoom->ListSearchables();

		cout << "Available Paths: ";
		if (CurrentRoom->GetNeighbourRoom('n') != nullptr)
			cout << "North ";
		if (CurrentRoom->GetNeighbourRoom('e') != nullptr)
			cout << "East ";
		if (CurrentRoom->GetNeighbourRoom('s') != nullptr)
			cout << "South ";
		if (CurrentRoom->GetNeighbourRoom('w') != nullptr)
			cout << "West ";
		cout << endl;
	}
	} while (true);
	return 0;
}





