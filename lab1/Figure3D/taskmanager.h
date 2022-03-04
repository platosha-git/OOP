#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "loadArgs.h"

enum CodeManager
{
    load,
    carry,
    scale,
    rotate,
    draw,
    fdelete
};

TError TaskManager(CodeManager code, ArgsManager args);

#endif // TASKMANAGER_H
