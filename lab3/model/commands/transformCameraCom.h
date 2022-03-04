#ifndef TRANSFORM_CAMERA_COM_H
#define TRANSFORM_CAMERA_COM_H

#include "command.h"
#include "point/point.hpp"
#include "controller/controller.h"

class TransformCameraCommand: public Command
{
public:
    TransformCameraCommand(char* _objectName, Point& _move, Point& _rotate);
    void execute(shared_ptr<Controller> controller) override;

private:
    char* objectName;
    Point move;
    Point rotate;
};

#endif // TRANSFORM_CAMERA_COM_H
