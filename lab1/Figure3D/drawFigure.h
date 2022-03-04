#ifndef LINE_H
#define LINE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>

#include "figure.h"

struct DrawFigureArgs
{
    QGraphicsScene *scene;
};

TError DrawFigure(Figure figure, DrawFigureArgs drawF);
void DrawCube(Figure figure, DrawFigureArgs drawF);
void AddLine(QGraphicsScene *scene, Pick point1, Pick point2);
void ClearScene(QGraphicsScene *scene);

#endif // LINE_H
