﻿#include "controller.h"

shared_ptr<Controller>Controller::instance()
{
    static shared_ptr<Controller> myInstance(new Controller());
    return myInstance;
}

Controller::Controller():
    renderer(new RenderManager)
{
    shared_ptr<BaseLoader> ldr(new FileLoader);
    shared_ptr<BaseModelBuilder> bld(new ModelBuilder);
    shared_ptr<UploadManager> _uploadManager(new UploadModel(ldr, bld));
    this->uploadManager = _uploadManager;
}

void Controller::addModel(char* _name, char* _fileName)
{
    shared_ptr<Model> model = uploadManager->loadModel(_name, _fileName);
    sceneManager.getScene()->addObject(shared_ptr<Model>(model));
    //scene_manager.getScene()->addModel(std::shared_ptr<Model>(model));
}

void Controller::addCamera(char* name)
{
    auto camera = new Camera(name);
    sceneManager.getScene()->addObject(shared_ptr<Camera>(camera));
    //scene_manager.getScene()->addCamera(std::shared_ptr<Camera>(camera));
}

void Controller::setCamera(char* cam_name)
{
    scene_manager.setCurrentCamera(cam_name);
}

void Controller::removeCamera(char* cam_name)
{
    auto scene = scene_manager.getScene();
    Vector<std::shared_ptr<Object>>cameras = scene->getObjects()->getObjects();
//    Vector<std::shared_ptr<Camera>>cameras = scene->getCameras();
    VectorIterator<std::shared_ptr<Object>> it(cameras.begin());
    VectorIterator<std::shared_ptr<Object>> it_e(cameras.end());
    while (it != it_e)
    {
        auto tmp = *it;
        if (strcmp(tmp->getName(), cam_name) ==  0)
            break;
        ++it;
    }
    time_t t_time = time(NULL);
    if (it!=it_e)
        scene->removeObject(it);
 //       scene->removeCamera(it);
    else
        throw ErrorCameraLack(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time),"No this camera");
}

void Controller::removeModel(char* model_name)
{
    auto scene = scene_manager.getScene();
    Vector<std::shared_ptr<Object>> objects = scene->getObjects()->getObjects();
    //Vector<std::shared_ptr<Object>>objects = scene->getObjects();
    VectorIterator<std::shared_ptr<Object>> it(objects.begin());
    VectorIterator<std::shared_ptr<Object>> it_e(objects.end());
    while (it != it_e)
    {
        auto tmp = *it;
        if (strcmp(tmp->getName(), model_name) ==  0)
            break;
        ++it;
    }
    time_t t_time = time(NULL);
    if (it!=it_e)
        scene->removeObject(it);
//        scene->removeModel(it);
    else
        throw ErrorObjectLack(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time),"No this object");
}

void Controller::transformCamera(char* cam_name, Point &move, Point &rotate)
{
    //auto camera = scene_manager.getScene()->getCamera(cam_name);
    auto camera = std::dynamic_pointer_cast<Camera>(scene_manager.getScene()->getObject(cam_name));
    transform_manager.moveObject(camera, move.getX(), move.getY(), move.getZ());
    camera_manager.roll(camera, rotate.getX());
    camera_manager.pitch(camera, rotate.getY());
    camera_manager.yaw(camera, rotate.getZ());
}

void Controller::transformModel(char* model_name, Point &move, Point &scale, Point &rotate)
{
    auto obj = scene_manager.getScene()->getObject(model_name);
    transform_manager.moveObject(obj, move.getX(), move.getY(), move.getZ());
    transform_manager.scaleObject(obj, scale.getX(), scale.getY(), scale.getZ());
    transform_manager.rotateObjectOX(obj, rotate.getX());
    transform_manager.rotateObjectOY(obj, rotate.getY());
    transform_manager.rotateObjectOZ(obj, rotate.getZ());
}

void Controller::draw(std::shared_ptr<BaseDrawer> drawer)
{
    renderer->setDrawer(drawer);
    renderer->setCamera(scene_manager.getCurrentCamera());
    scene_manager.getScene()->getObjects()->accept(renderer);
    //scene_manager.getScene()->getModelsComposite()->accept(renderer);
}
