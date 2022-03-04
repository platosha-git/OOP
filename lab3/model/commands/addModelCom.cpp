#include "addModelCom.h"

AddModelCommand::AddModelCommand(char *_modelName, char* _fileName) :
    modelName(_modelName),
    fileName(_fileName)
{
}

void AddModelCommand::execute(shared_ptr<Controller> controller)
{
    controller->addModel(modelName, fileName);
}
