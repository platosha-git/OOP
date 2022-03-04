#include "controlBlock.h"

ControlBlock::ControlBlock(QObject *parent) :
    QObject(parent),
    curFloor(0),
    step(1),
    curStatus(free)
{
    for (int i = 0; i < numFloors; i++) {
        calls[i] = false;
    }
}

void ControlBlock::addOrder(int floor)
{
    if (curStatus == free || curStatus == busy) {
        curStatus = busy;
        calls[floor - 1] = true;
        int nextOrder = receiveOrder();
        emit sentOrder(nextOrder);
    }
}

void ControlBlock::toFree(int floor)
{
    if (curStatus == busy) {
        curFloor = floor;
        calls[floor - 1] = false;

        if (isEmptyOrderList()) {
            curStatus = free;
        } else {
            int nextOrder = receiveOrder();
            emit sentOrder(nextOrder);
        }
    }
}

void ControlBlock::toBusy(int floor)
{
    qDebug() << "Crossing" << floor << "floor";
}

bool ControlBlock::isEmptyOrderList()
{
    bool res = true;
    for (int i = 0; i < numFloors && res; i++) {
        if (calls[i]) {
            res = false;
        }
    }
    return res;
}

int ControlBlock::receiveOrder()
{
    int res = -1;

    for (int i = curFloor; i <= numFloors && i > -1 && res == -1; i += step)
    {
        if (calls[i - 1]) {
            res = i;
        }
    }

    for (int i = curFloor; i <= numFloors && i > -1 && res == -1; i -= step) {
        if (calls[i - 1]) {
            res = i;
        }
    }
    return res;
}

