#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "objects/invisible_object.h"
#include "point/point.hpp"
#include "matrix/matrix_4x4.hpp"

class Camera: public InvisibleObject
{
public:
    Camera(char* name);

    const Point &getPosition() const;
    void setPosition(const Point &position);

    double getXAngle() const;
    void setXAngle(double x_angle);

    double getYAngle() const;
    void setYAngle(double y_angle);

    double getZAngle() const;
    void setZAngle(double z_angle);

    void transform(const std::shared_ptr<Matrix4x4> mtr) override;
    void accept(std::shared_ptr<Visitor> visitor) override;

private:
    Point position;
    double x_angle;
    double y_angle;
    double z_angle;
};

#endif // CAMERA_HPP
