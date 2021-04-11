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

	CurrentRoom->CreateRoom('n', Dialogue->getDescription(4), true); // locked room (cave)



	vector<Item*> Inventory;

	bool CavePath[5] = { 0,0,1,0,1 }; //right = 0, left = 1;
	bool CurrentCavePath[5];
	short CaveArrPos = 0;

	CurrentRoom->GetNeighbourRoom('s')->AddSearchable("Drawer", new Item("Note"));
	CurrentRoom->GetNeighbourRoom('s')->GetNeighbourRoom('w')->AddSearchable("Closet");
	CurrentRoom->GetNeighbourRoom('s')->GetNeighbourRoom('w')->AddSearchable("Drawer");
	CurrentRoom->GetNeighbourRoom('s')->GetNeighbourRoom('w')->AddSearchable("Bag", new Item("Key"));
	CurrentRoom->GetNeighbourRoom('s')->GetNeighbourRoom('w')->AddSearchable("Purse");
	CurrentRoom->GetNeighbourRoom('s')->GetNeighbourRoom('w')->AddSearchable("Cabinet");


	cout << "======================================\n";
	cout << "Welcome to the Mansion of Doom!\n";
	cout << "======================================\n\n";
	cout << "Your goal is to escape the mansion using your wits and the 'help' found within\n\n";
	cout << "type help help into the console to recieve example commands to help you along the way\n";
	cout << "*Note* commands are Case-Sensitive, so be careful...\n";
	cout << "\nGood Luck...\n\n";

	system("pause");

	string action, object;
	do {

		system("cls");
		cout << CurrentRoom->GetDescription() << endl;
		if (CurrentRoom->GetDescription() == Dialogue->getDescription(2))
		{
			cout << Dialogue->getRiddle(0) << endl;
			cout << Dialogue->getRiddle(1) << endl;
			cout << Dialogue->getRiddle(2) << endl;
		}
		cout << "Searchables:";
		cout << CurrentRoom->ListSearchables();

		cout << "Available Paths: ";
		if (CurrentRoom->GetDescription() != Dialogue->getDescription(4))
		{
			if (CurrentRoom->GetNeighbourRoom('n') != nullptr)
				cout << "North ";
			if (CurrentRoom->GetNeighbourRoom('e') != nullptr)
				cout << "East ";
			if (CurrentRoom->GetNeighbourRoom('s') != nullptr)
				cout << "South ";
			if (CurrentRoom->GetNeighbourRoom('w') != nullptr)
				cout << "West ";
		}
		else cout << "Right, Left";
		cout << endl;
		cin >> action >> object;
		system("cls");
		if (action == "go" || action == "Go" || action == "move" || action == "Move")
		{
			if (object == "n" || object == "N" || object == "north" || object == "North")
			{
				if (CurrentRoom->GetNeighbourRoom('n') != nullptr)
				{
					if (!CurrentRoom->GetNeighbourRoom('n')->isLocked())
					{
						StackOfRooms->push(CurrentRoom);
						CurrentRoom = CurrentRoom->GetNeighbourRoom('n');
					}
					else
					{
						cout << "Door is Locked\n";
						system("pause");
					}
				}
				else
				{
					cout << "\aERROR: Room not found\n";
					system("pause");
				}
			}

			else if (object == "e" || object == "E" || object == "east" || object == "East")
			{
				if (CurrentRoom->GetNeighbourRoom('e') != nullptr)
				{
					if (!CurrentRoom->GetNeighbourRoom('e')->isLocked())
					{
						StackOfRooms->push(CurrentRoom);
						CurrentRoom = CurrentRoom->GetNeighbourRoom('e');
					}
					else
					{
						cout << "Door is Locked\n";
						system("pause");
					}
				}
				else
				{
					cout << "\aERROR: Room not found\n";
					system("pause");
				}
			}
			else if (object == "s" || object == "S" || object == "south" || object == "South")
			{
				if (CurrentRoom->GetNeighbourRoom('s') != nullptr)
				{
					if (!CurrentRoom->GetNeighbourRoom('s')->isLocked())
					{
						StackOfRooms->push(CurrentRoom);
						CurrentRoom = CurrentRoom->GetNeighbourRoom('s');
					}
					else
					{
						cout << "Door is Locked\n";
						system("pause");
					}
				}
				else
				{
					cout << "\aERROR: Room not found\n";
					system("pause");
				}
			}
			else if (object == "w" || object == "W" || object == "west" || object == "West")
			{
				if (CurrentRoom->GetNeighbourRoom('w') != nullptr)
				{
					if (!CurrentRoom->GetNeighbourRoom('w')->isLocked())
					{
						StackOfRooms->push(CurrentRoom);
						CurrentRoom = CurrentRoom->GetNeighbourRoom('w');
					}
					else
					{
						cout << "Door is Locked\n";
						system("pause");
					}
				}
				else
				{
					cout << "\aERROR: Room not found\n";
					system("pause");
				}
			}
			else if (object == "b" || object == "B" || object == "back" || object == "Back")
			{
				if (CurrentRoom->GetDescription() != Dialogue->getDescription(4))
				{
					Room* temp = nullptr;
					StackOfRooms->pop(temp);
					CurrentRoom = temp;
				}
				else
				{
					cout << "you are unable to go back";
					system("pause");
				}
			}
			else if (object == "l" || object == "L" || object == "left" || object == "Left" && CurrentRoom->GetDescription() == Dialogue->getDescription(4))
			{
				CurrentCavePath[CaveArrPos] = 1;
				CaveArrPos++;
				cout << "You run to the left (" << CaveArrPos << "/5)\n";
				system("pause");
			}
			else if (object == "r" || object == "R" || object == "right" || object == "Right" && CurrentRoom->GetDescription() == Dialogue->getDescription(4))
			{
				CurrentCavePath[CaveArrPos] = 0;
				CaveArrPos++;
				cout << "You run to the right (" << CaveArrPos << "/5)\n";
				system("pause");
			}
			else
			{
				cout << "\aERROR: Invalid Room \"" << object << "\"\n";
				system("pause");
			}

			if (CaveArrPos == 5)
			{
				for (unsigned i = 0; i < 4; i++)
				{
					if (CurrentCavePath[i] != CavePath[i])
					{
						system("cls");
						cout << Dialogue->getEnding(3) << endl;
						system("pause");
						exit(1);
					}
				}
				system("cls");
				cout << Dialogue->getEnding(1) << endl;
				system("pause");
				exit(1);
			}


		}
		else if (action == "use" || action == "Use")
		{
			bool ObjFound = false;
			for (Item* item : Inventory)
			{
				if (object == "key" || object == "Key")
				{
					if (item->Name == "Key") {
						ObjFound = true;
						if (CurrentRoom->GetNeighbourRoom('n') != nullptr)
							if (CurrentRoom->GetNeighbourRoom('n')->isLocked())
							{
								CurrentRoom->GetNeighbourRoom('n')->Unlock();
								cout << "North Door Unlocked\n";
								break;
							}
						if (CurrentRoom->GetNeighbourRoom('e') != nullptr)
							if (CurrentRoom->GetNeighbourRoom('e')->isLocked())
							{
								CurrentRoom->GetNeighbourRoom('e')->Unlock();
								cout << "East Door Unlocked\n";
								break;
							}
						if (CurrentRoom->GetNeighbourRoom('s') != nullptr)
							if (CurrentRoom->GetNeighbourRoom('s')->isLocked())
							{
								CurrentRoom->GetNeighbourRoom('s')->Unlock();
								cout << "South Door Unlocked\n";
								break;
							}
						if (CurrentRoom->GetNeighbourRoom('w') != nullptr)
							if (CurrentRoom->GetNeighbourRoom('w')->isLocked())
							{
								CurrentRoom->GetNeighbourRoom('w')->Unlock();
								cout << "West Door Unlocked\n";
								break;
							}
						if (CurrentRoom->GetDescription() == Dialogue->getDescription(2))
						{
							cout << Dialogue->getEnding(2) << endl;
							system("pause");
							exit(1);
						}
						cout << "key cannot be used here\n";
						system("pause");
					}
				}
				if (object == "note" || object == "Note")
				{
					if (item->Name == "Note") {
						cout << "The note Reads: \n";
						cout << "1. left follows after right\n2. you always begin with a left\n3. 1. only becomes true after going left at least once\n4. the first two directions are the same\n5. 2. is false\n6. the third direction is opposite to direction you began with\n7. your first left should follow with a right\n";
						ObjFound = true;
						break;
					}
				}
			}
			if (ObjFound == false)
			{
				cout << "\aERROR: Invalid Item \"" << object << "\"\n";
			}
			system("pause");
		}
		else if (action == "search" || action == "Search" || action == "Look" || action == "look")
		{
			Item* item = CurrentRoom->Search(object);

			if (CurrentRoom->GetDescription() == Dialogue->getDescription(3) && item == nullptr)
			{
				cout << Dialogue->getEnding(0) << endl;
				system("pause");
				exit(1);
			}
			if (item != nullptr)
				cout << item->Name;
				Inventory.push_back(item);
				cout << Inventory.size();

			system("pause");
		}
		else {
			cout << "\aERROR: Invalid Command \"" << action << " " << object << "\"\n";
			cout << "Valid Actions: \"Go\" \"Use\" \"Search\" \"Move\"\n";
			cout << "Valid Objects: \"Key\" \"Note\" \"North\" \"East\" \"South\" \"Drawer\" \"Cabinet\"\n";
			cout << "Examples: \"Go North\" \"Use Key\" \"Move South\" \"Use Note\" \"Go Back\" \"Search Purse\"\n";
			system("pause");
		}
	} while (true);
	return 0;
}





