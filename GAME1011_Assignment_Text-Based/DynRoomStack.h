#ifndef DYNROOMSTACK_H
#define DYNROOMSTACK_H
#include"Room.h"

class DynRoomStack
{
private:
    class RoomNode
    {
        friend class DynRoomStack;
        Room* SavedRoom;
        RoomNode* next;
        RoomNode(Room* sRoom, RoomNode* next1 = NULL)
        {
            SavedRoom = sRoom;
            next = next1;
        }
    };

    RoomNode* top;
public:
    DynRoomStack() { top = NULL; }
    Room* getTop();
    void push(Room* newRoom);
    void pop(Room* &removeRoom);
    bool isEmpty() const;
};
#endif