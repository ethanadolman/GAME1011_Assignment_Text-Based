#include <iostream>
#include "Room.h"
#include "TextManager.h"
using namespace std;

int main()
{
	system("color F");
	// Create Text Arrays
	TextManager* Dialogue = new TextManager();

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
	char choice;
	cout << CurrentRoom->GetDescription() << endl;
	do {
		cin >> choice;
		if (CurrentRoom->GetNeighbourRoom(choice) != nullptr)
		{
			system("cls");
			CurrentRoom = CurrentRoom->GetNeighbourRoom(choice);
			cout << CurrentRoom->GetDescription() << endl;
			cout << "Searchables:";
			cout << CurrentRoom->ListSearchables();
			/*Item* item = CurrentRoom->Search("Drawer");
			if (item != nullptr)
				Inventory.push_back(item);
			cout << Inventory[0]->Name;*/
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
		else cout << "\aERROR: Invalid Room\n";

	} while (true);
	return 0;
}





