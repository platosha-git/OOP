#ifndef TRANSFORM_COMMAND_H
#define TRANSFORN_COMMAND_H

#include "command.h"
#include "point/point.hpp"
#include "controller/controller.h"

class TransformModelCommand: public Command
{
public:
    TransformModelCommand(char* _objectName, Point& _move, Point& _scale, Point& _rotate);
    void execute(shared_ptr<Controller> controller) override;

private:
    char* objectName;
    Point move;
    Point scale;
    Point rotate;
};

#endif // TRANSFORM_COMMAND_H
