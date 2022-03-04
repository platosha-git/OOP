#include "removeModelCom.h"

RemoveModelCommand::RemoveModelCommand(char* _objectName) :
    objectName(_objectName)
{
}

void RemoveModelCommand::execute(shared_ptr<Controller> controller)
{
    controller->removeModel(objectName);
}

