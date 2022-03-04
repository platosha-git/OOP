#include "managers/render_manager.hpp"

void RenderManager::setDrawer(std::shared_ptr<BaseDrawer> drawer)
{
    this->drawer = drawer;
}

void RenderManager::setCamera(std::shared_ptr<Camera> camera)
{
    this->camera = camera;
}

void RenderManager::visit(Model &model)
{
    time_t t_time = time(NULL);
    if (!drawer)
    {
        throw ErrorDrawerLack(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time),"Drawer wasn't set");
    }
    if (!camera)
    {
        throw ErrorCameraLack(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time),"Camera wasn't set");
    }

    auto mesh = model.getMesh();
    auto lines = mesh->getLines();
    int n = lines.get_size();
    for (int i = 0; i < n; i++)
    {
        proectPoint(lines[i].first);
        proectPoint(lines[i].second);
        drawer->drawLine(lines[i].first, lines[i].second);
    }
}


void RenderManager::proectPoint(Point &point)
{
    Point cam_pos(camera->getPosition());
    std::shared_ptr<Matrix4x4> transform_matrix(new MoveMatrix4x4(-cam_pos.getX(), -cam_pos.getY(), 0));
    point.transform(transform_matrix);
    transform_matrix.reset(new RotateOxMatrix4x4(-camera->getXAngle()));
    point.transform(transform_matrix);
    transform_matrix.reset(new RotateOyMatrix4x4(-camera->getYAngle()));
    point.transform(transform_matrix);
    transform_matrix.reset(new RotateOzMatrix4x4(-camera->getZAngle()));
    point.transform(transform_matrix);

    double eps = 1e-10;
    double znam = point.getZ() + cam_pos.getZ();
    if (znam < eps && znam > -eps)
    {
        znam = eps;
    }
    double distCoef = cam_pos.getZ() / znam;
    point.setX(point.getX() * distCoef);
    point.setY(point.getY() * distCoef);
}











void RenderManager::visit(Camera &camera)
{
}

void RenderManager::visit(Composite& composite)
{
}
