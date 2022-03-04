#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QObject>
#include <QTextEdit>
#include "cabin.h"
#include "controlBlock.h"

class Lift : public QObject
{
    Q_OBJECT

public:
    Lift();
    void acceptOrder(int floor);

private:
    ControlBlock controlBlock;
    Cabin cabin;
    Doors doors;
};

#endif // ELEVATOR_H
