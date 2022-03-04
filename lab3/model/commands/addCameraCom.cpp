#include "addCameraCom.h"

AddCameraCommand::AddCameraCommand(char *_name) :
    name(_name)
{
}

void AddCameraCommand::execute(std::shared_ptr<Controller> controller)
{
    controller->addCamera(name);
}
