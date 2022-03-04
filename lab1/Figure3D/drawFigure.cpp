#include "drawFigure.h"

TError DrawFigure(Figure figure, DrawFigureArgs drawF)
{
    if (IsEmptyFigure(figure)) {
        return EMPTY_FIGURE;
    }

    ClearScene(drawF.scene);
    DrawCube(figure, drawF);

    return SUCCESS;
}

void ClearScene(QGraphicsScene *scene)
{
    scene->clear();
}

void DrawCube(Figure figure, DrawFigureArgs drawF)
{
    for (int i = 0; i < figure.NumRibs; i++) {
        int p1 = figure.RibsArray[i].Point1;
        int p2 = figure.RibsArray[i].Point2;
        AddLine(drawF.scene, figure.PicksArray[p1], figure.PicksArray[p2]);
    }
}

void AddLine(QGraphicsScene *scene, Pick point1, Pick point2)
{
    scene->addLine(point1.X, point1.Y, point2.X, point2.Y);
}
