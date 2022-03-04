#include "commands/transformModelCom.h"

TransformModelCommand::TransformModelCommand(char* _objectName, Point& _move, Point& _scale, Point& _rotate) :
    objectName(_objectName),
    move(_move),
    scale(_scale),
    rotate(_rotate)
{
}

void TransformModelCommand::execute(shared_ptr<Controller> controller)
{
    controller->transformModel(objectName, move, scale, rotate);
}


