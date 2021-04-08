#include <iostream>
#include "DynRoomStack.h"
#include <cstdlib>
using namespace std;

Room* DynRoomStack::getTop()
{
    return top->SavedRoom;
}

//**************************************************
// Member function push pushes the argument onto   *
// the stack.                                      *
//**************************************************
void DynRoomStack::push(Room * newRoom)
{
    top = new RoomNode(newRoom, top);
}

//*****************************************************
// Member function pop removes the value at the top   *
// of the stack and copies it into the variable       *
// passed as an argument.                             *
//*****************************************************
void DynRoomStack::pop(Room* removeRoom)
{
    RoomNode* temp;

    if (isEmpty())
    {
        cout << "The stack is empty.\n";
        //exit(1);
    }
    else   // Pop value off top of stack
    {
        removeRoom = top->SavedRoom;
        temp = top;
        top = top->next;
        delete temp;
    }
}

//*****************************************************
// Member function isEmpty returns true if the stack  *
// is empty, or false otherwise.                      *
//*****************************************************
bool DynRoomStack::isEmpty() const
{
    if (!top)
        return true;
    else
        return false;
}
