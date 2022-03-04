#ifndef CAMERA_MANAGER_HPP
#define CAMERA_MANAGER_HPP

#include "managers/manager.h"
#include "objects/camera/camera.hpp"
#include <math.h>


class CameraManager: public Manager
{
public:
    void yaw(std::shared_ptr<Camera> camera, double angle);
    void roll(std::shared_ptr<Camera> camera, double angle);
    void pitch(std::shared_ptr<Camera> camera, double angle);
};


#endif // CAMERA_MANAGER_HPP
