//test

#include <iostream>
#include "Room.h"
#include "TextManager.h"
using namespace std;

int main()
{
	// Create Text Arrays
	TextManager* Dialogue = new TextManager();

	// Create First room
	Room* CurrentRoom = new Room(Dialogue->getDescription(0));

	CurrentRoom->CreateRoom('s', Dialogue->getDescription(1)); //room with cave note in drawer

	CurrentRoom->GetNeighbourRoom('s')->CreateRoom('e', Dialogue->getDescription(2)); // 3 man riddle

	CurrentRoom->GetNeighbourRoom('s')->CreateRoom('w', Dialogue->getDescription(3)); //bedroom

	CurrentRoom->CreateRoom('n', Dialogue->getDescription(4)); // locked room (cave)

	CurrentRoom->CreateRoom('e', Dialogue->getDescription(5)); //infinite loop room


	if (CurrentRoom->GetNeighbourRoom('n') != nullptr)
		CurrentRoom->GetDescription() + "\n" + Dialogue->getDoors(0);

	if (CurrentRoom->GetNeighbourRoom('e') != nullptr)
		CurrentRoom->GetDescription() + "\n" + Dialogue->getDoors(1);

	if (CurrentRoom->GetNeighbourRoom('s') != nullptr)
		CurrentRoom->GetDescription() + "\n" + Dialogue->getDoors(2);

	if (CurrentRoom->GetNeighbourRoom('w') != nullptr)
		CurrentRoom->GetDescription() + "\n" + Dialogue->getDoors(3);



	char choice;
	cout << CurrentRoom->GetDescription() << endl;
	do {
		cin >> choice;
		if (CurrentRoom->GetNeighbourRoom(choice) != nullptr)
		{
			cout << "Moved " << choice << endl;
			CurrentRoom = CurrentRoom->GetNeighbourRoom(choice);
			cout << CurrentRoom->GetDescription() << endl;
			
		}
		else cout << "\aERROR: Invalid Room\n";

	} while (true);
	return 0;
}





