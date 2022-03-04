#include "removeCameraCom.h"

RemoveCameraCommand::RemoveCameraCommand(char* _objectName):
    objectName(_objectName)
{
}

void RemoveCameraCommand::execute(std::shared_ptr<Controller> controller)
{
    controller->removeCamera(objectName);
}

