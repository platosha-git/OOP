#ifndef ADD_MODEL_COM_H
#define ADD_MODEL_COM_H

#include <string>
#include "command.h"
#include "controller/controller.h"

class AddModelCommand: public Command
{
public:
    explicit AddModelCommand(char* _modelName, char* _fileName);
    void execute(shared_ptr<Controller> controller) override;

private:
    char* modelName;
    char* fileName;
};



#endif // ADD_MODEL_COM_H
