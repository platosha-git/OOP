#include "camera.hpp"


Camera::Camera(char *name)
{
    this->name = name;
    position = Point(0, 0, 300);
    this->x_angle = 0;
    this->y_angle = 0;
    this->z_angle = 0;
}

const Point &Camera::getPosition() const
{
    return position;
}

void Camera::setPosition(const Point &position)
{
    this->position = position;
}

double Camera::getXAngle() const
{
    return x_angle;
}

void Camera::setXAngle(double x_angle)
{
    this->x_angle = x_angle;
}

double Camera::getYAngle() const
{
    return y_angle;
}

void Camera::setYAngle(double y_angle)
{
    this->y_angle = y_angle;
}

void Camera::setZAngle(double z_angle)
{
    this->z_angle = z_angle;
}

double Camera::getZAngle() const
{
    return z_angle;
}

void Camera::transform(const std::shared_ptr<Matrix4x4> mtr)
{
    position.transform(mtr);
}

void Camera::accept(std::shared_ptr<Visitor> visitor)
{
    visitor->visit(*this);
}

