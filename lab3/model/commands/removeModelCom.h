#ifndef REMOVE_MODEL_COM_H
#define REMOVE_MODEL_COM_H

#include "command.h"
#include "controller/controller.h"

class RemoveModelCommand: public Command
{
public:
    RemoveModelCommand(char* _objectName);
    void execute(shared_ptr<Controller> controller) override;

private:
    char* objectName;
};


#endif // REMOVE_MODEL_COM_H
