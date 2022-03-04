#include "commands/setCameraCom.h"

SetCameraCommand::SetCameraCommand(char* _name) :
    name(_name)
{
}

void SetCameraCommand::execute(shared_ptr<Controller> controller)
{
    controller->setCamera(name);
}


