#include "doors.h"

const int DoorsProcess = 100;
const int DoorsWait = 200;

Doors::Doors(QObject *parent) :
    QObject(parent),
    curStatus(closeState)
{
    openT.setInterval(DoorsProcess);
    openT.setSingleShot(true);

    waitT.setInterval(DoorsWait);
    waitT.setSingleShot(true);

    closeT.setInterval(DoorsProcess);
    closeT.setSingleShot(true);

    connect(&openT, SIGNAL(timeout()), this, SLOT(toOpenState()));
    connect(&waitT, SIGNAL(timeout()), this, SLOT(toCloseProcess()));
    connect(&closeT, SIGNAL(timeout()), this, SLOT(toCloseState()));
}

void Doors::toOpenProcess()
{
    if (curStatus == closeState || curStatus == closeProcess) {
        curStatus = openProcess;
        qDebug() << "Doors:\n\topeninig";
        openT.start(DoorsProcess);
    }
}

void Doors::toCloseProcess()
{
    if (curStatus == openState) {
        curStatus = closeProcess;
        qDebug() << "\tclosing";
        closeT.start(DoorsProcess);
    }
}

void Doors::toOpenState()
{
    if (curStatus == openProcess) {
        curStatus = openState;
        qDebug() << "\topen";
        waitT.start(DoorsWait);
    }
}

void Doors::toCloseState()
{
    if (curStatus == closeProcess) {
        curStatus = closeState;
        qDebug() << "\tclosed";
        emit closeDoors();
    }
}
