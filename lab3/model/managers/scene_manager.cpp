#include "scene_manager.hpp"

SceneManager::SceneManager()
    : scene(new Scene()){}

std::shared_ptr<Scene> SceneManager::getScene()
{
    return scene;
}

void SceneManager::setCurrentCamera(char *name)
{
    current_camera = std::dynamic_pointer_cast<Camera>(scene->getObject(name));
}

std::shared_ptr<Camera> SceneManager::getCurrentCamera()
{
    time_t t_time = time(NULL);
    if (!current_camera)
    {
       throw ErrorCameraLack(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return current_camera;
}

