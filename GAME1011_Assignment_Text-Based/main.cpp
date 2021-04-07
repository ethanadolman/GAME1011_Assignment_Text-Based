//test

#include <iostream>
#include "Room.h"
using namespace std;

int main()
{
	Room* CurrentRoom = new Room();
	CurrentRoom->CreateRoom('n'); // locked room (cave)
	CurrentRoom->CreateRoom('e'); //infinite loop room
	CurrentRoom->CreateRoom('s'); //room with cave note in drawer
	CurrentRoom->GetNeighbourRoom('s')->CreateRoom('w'); //bedroom
	CurrentRoom->GetNeighbourRoom('s')->CreateRoom('e'); // 3 man riddle

	char choice;
	do {
		cin >> choice;
		if (CurrentRoom->GetNeighbourRoom(choice) != nullptr)
		{
			cout << "Moved " << choice << endl;
			CurrentRoom = CurrentRoom->GetNeighbourRoom(choice);
			cout << CurrentRoom->GetDescription();
			
		}
		else cout << "\aERROR: Invalid Room\n";

	} while (true);
	return 0;
}





