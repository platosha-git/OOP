#ifndef RENDER_COM_H
#define RENDER_COM_H

#include <string>
#include "command.h"
#include "controller/controller.h"

class RenderCommand: public Command
{
public:
    explicit RenderCommand(shared_ptr<BaseDrawer> _drawer);
    void execute(shared_ptr<Controller> controller) override;

private:
    shared_ptr<BaseDrawer> drawer;
    shared_ptr<AbstractGraphFactory> factory;
};


#endif // RENDER_COM_H
