#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include <memory>

#include "managers/camera_manager.hpp"
#include "managers/scene_manager.hpp"
#include "managers/upload_manager.h"
#include "upload/file_loader.hpp"
#include "upload/model_builder.hpp"
#include "upload/upload_model.hpp"
#include "upload/director_model.hpp"
#include "managers/transform_manager.hpp"
#include "managers/render_manager.hpp"

class Controller
{
public:
    static shared_ptr<Controller> instance();
    Controller(const Controller&) = delete;

    Controller& operator=(const Controller&) = delete;
    ~Controller() = default;

    void addModel(char* _modelName, char* _fileName);
    void addCamera(char* _cameraName);
    void setCamera(char* _cameraName);
    void removeCamera(char* _cameraName);
    void removeModel(char* _modelName);

    void transformCamera(char* _cameraName, Point& _move, Point& _rotate);
    void transformModel(char* _modelName, Point& _move, Point& _scale, Point& _rotate);

    void draw(shared_ptr<BaseDrawer> drawer);

private:
    Controller();
    CameraManager cameraManager;
    SceneManager sceneManager;
    TransformManager transformManager;
    shared_ptr<UploadManager> uploadManager;
    shared_ptr<RenderManager> renderer;
};

#endif  // CONTROLLER_H
