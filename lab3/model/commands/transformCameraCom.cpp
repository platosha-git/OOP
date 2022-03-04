#include "commands/transformCameraCom.h"


TransformCameraCommand::TransformCameraCommand(char* _objectName, Point& _move, Point& _rotate):
    objectName(_objectName),
    move(_move),
    rotate(_rotate)
{
}

void TransformCameraCommand::execute(shared_ptr<Controller> controller)
{
    controller->transformCamera(objectName, move, rotate);
}


