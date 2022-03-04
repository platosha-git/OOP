#include "renderCom.h"

RenderCommand::RenderCommand(shared_ptr<BaseDrawer> _drawer) :
    drawer(_drawer)
{
}

void RenderCommand::execute(shared_ptr<Controller> controller)
{
    controller->draw(drawer);
}


