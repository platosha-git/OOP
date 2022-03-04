#ifndef LOADARGS_H
#define LOADARGS_H

#include "loadFigure.h"
#include "drawFigure.h"
#include "moveFigure.h"
#include "scaleFigure.h"
#include "rotateFigure.h"

struct ArgsManager
{    
    union
    {
        LoadFigureArgs loadF;
        MoveFigureArgs moveF;
        ScaleFigureArgs scaleF;
        RotateFigureArgs rotateF;
    };

    DrawFigureArgs drawF;
};

void LoadArgsToLoadFigure(ArgsManager &args, const char *fname);
void LoadArgsToDrawFigure(ArgsManager &args, QGraphicsScene *scene);
TError LoadArgsToMoveFigure(ArgsManager &args, QString qdx, QString qdy, QString qdz);
TError LoadArgsToScaleFigure(ArgsManager &args, QString qkx, QString qky, QString qkz,
                                                QString qx, QString qy, QString qz);
TError LoadArgsToRotateFigure(ArgsManager &args, QString qangle, QString qx, QString qy, QString qz);
void LoadArgsToDeleteFigure(ArgsManager &args);

#endif // LOADARGS_H
