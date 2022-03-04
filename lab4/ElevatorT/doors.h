#ifndef DOORS_H
#define DOORS_H

#include <QObject>
#include <QTextBrowser>
#include <QTimer>
#include "qdebug.h"

class Doors : public QObject
{
    Q_OBJECT

    enum DoorsStatus
    {
        openState,
        openProcess,
        closeState,
        closeProcess
    };

public:
    explicit Doors(QObject *parent = nullptr);

signals:
    void openDoors();
    void closeDoors();

public slots:
    void toOpenProcess();
    void toCloseProcess();
    void toOpenState();
    void toCloseState();

private:
    DoorsStatus curStatus;
    QTimer openT;
    QTimer closeT;
    QTimer waitT;
};

#endif // DOORS_H
