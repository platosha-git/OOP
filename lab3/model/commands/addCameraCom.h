#ifndef ADD_CAMERA_COM_H
#define ADD_CAMERA_COM_H

#include <string>
#include "command.h"
#include "controller/controller.h"

class AddCameraCommand: public Command
{
public:
    explicit AddCameraCommand(char* _name);
    void execute(shared_ptr<Controller> controller) override;
private:
    char* name;
};

#endif // ADD_CAMERA_COM_H
