#include "cabin.h"

const int crossT = 100;

Cabin::Cabin(QObject *parent) :
    QObject(parent),
    curFloor(1),
    step(1),
    curStatus(wait)
{
    crossFloorT.setInterval(crossT);
    crossFloorT.setSingleShot(true);

    connect(&crossFloorT, SIGNAL(timeout()), this, SLOT(toMove()));
    connect(this, SIGNAL(finishOrder(int)), this, SLOT(toWait()));

    connect(this, SIGNAL(beginMove()), &doors, SLOT(toCloseProcess()));
    connect(this, SIGNAL(stopMove(int)), &doors, SLOT(toOpenProcess()));
    connect(&doors, SIGNAL(closeDoors()), this, SLOT(toMove()));
}

void Cabin::toMove()
{
    if (curStatus == receiveOrder || curStatus == move) {
        if (curStatus == move) {
            curFloor += step;
        }

        curStatus = move;

        if (curFloor == nextFloor) {
            emit finishOrder(curFloor);
        } else {
            emit toNextFloor(curFloor, step);
            crossFloorT.start(crossT);
        }
    }
}

void Cabin::toWait()
{
    if (curStatus == move) {
        curStatus = wait;
        qDebug() << "Stop on" << curFloor << "floor";
        emit stopMove(curFloor);
    }
}

void Cabin::toReceiveOrder(int floor)
{
    if (curStatus == wait) {
        curStatus = receiveOrder;
        nextFloor = floor;

        step = 1;
        if (curFloor > nextFloor) {
            step *= -1;
        }
        emit toMove();
    }
}

