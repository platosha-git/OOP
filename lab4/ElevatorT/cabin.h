#ifndef CABIN_H
#define CABIN_H

#include <QObject>
#include <QString>
#include "doors.h"

class Cabin : public QObject
{
    Q_OBJECT

    enum CabinStatus
    {
        receiveOrder,
        move,
        wait
    };

public:
    explicit Cabin(QObject *parent = nullptr);

signals:
    void beginMove();
    void toNextFloor(int floor, int step);
    void finishOrder(int floor);
    void stopMove(int floor);

public slots:
    void toMove();
    void toWait();
    void toReceiveOrder(int floor);


private:
    int curFloor;
    int nextFloor;
    int step;
    CabinStatus curStatus;
    Doors doors;
    QTimer crossFloorT;
};

#endif // CABIN_H
