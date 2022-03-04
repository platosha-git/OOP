#include "lift.h"

Lift::Lift()
{
    connect(&controlBlock, SIGNAL(sentOrder(int)), &cabin, SLOT(toReceiveOrder(int)));
    connect(&cabin, SIGNAL(toNextFloor(int, int)), &controlBlock, SLOT(toBusy(int)));
    connect(&cabin, SIGNAL(stopMove(int)), &controlBlock, SLOT(toFree(int)));
}

void Lift::acceptOrder(int floor)
{
    controlBlock.addOrder(floor);
}
