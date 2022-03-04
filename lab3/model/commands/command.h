#ifndef COMMAND_H
#define COMMAND_H

#include <memory>

class Controller;

class Command
{
public:
    virtual ~Command() = default;
    virtual void execute(std::shared_ptr<Controller>) = 0;
};


#endif // COMMAND_H
