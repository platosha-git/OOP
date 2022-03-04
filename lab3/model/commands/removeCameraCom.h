#ifndef REMOVE_CAMERA_COM_H
#define REMOVE_CAMERA_COM_H

#include "command.h"
#include "controller/controller.h"

class RemoveCameraCommand: public Command
{
public:
    RemoveCameraCommand(char *_objectName);
    void execute(shared_ptr<Controller> controller) override;

private:
    char* objectName;
};


#endif // REMOVE_CAMERA_COM_H
