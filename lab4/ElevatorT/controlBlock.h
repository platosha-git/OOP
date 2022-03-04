#ifndef CONTROLBLOCK_H
#define CONTROLBLOCK_H

#include <QObject>
#include <QVector>
#include <QString>
#include <iostream>
#include "qdebug.h"

const int numFloors = 5;

class ControlBlock : public QObject
{
    Q_OBJECT

    enum CBStatus
    {
        free,
        busy
    };

public:
    explicit ControlBlock(QObject *parent = nullptr);
    void addOrder(int floor);
    bool isEmptyOrderList();
    int receiveOrder();

signals:
    void sentOrder(int floor);

public slots:
    void toFree(int floor);
    void toBusy(int floor);

private:
    int curFloor;
    int step;
    CBStatus curStatus;
    bool calls[numFloors];
};

#endif // CONTROLBLOCK_H
