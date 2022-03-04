#ifndef SET_CAMERA_HPP
#define SET_CAMERA_HPP

#include <string>
#include "command.h"
#include "controller/controller.h"


class SetCameraCommand: public Command
{
public:
    explicit SetCameraCommand(char* _name);
    void execute(shared_ptr<Controller> Controller) override;
private:
    char* name;
};

#endif // SET_CAMERA_HPP
