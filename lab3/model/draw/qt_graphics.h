#ifndef QT_GRAPHICS_H
#define QT_GRAPHICS_H

#include <iostream>
#include "draw/base_graphics.h"

class QtGraphics: public BaseGraphics
{
public:
    QtGraphics(){}
      // std::cout<<"Constructor QtGraphics"<<std::endl;
    ~QtGraphics() override{}
  //     std::cout<<"Destructor QtGraphics"<<std::endl;}
};

#endif // QT_GRAPHICS_H
