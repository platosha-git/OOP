#include "rotateFigure.h"

#define AngleToRadian M_PI / 180;

TError RotateFigure(Figure& figure, RotateFigureArgs rotateF)
{
    if (IsEmptyFigure(figure)) {
        return EMPTY_FIGURE;
    }

    rotateF.Angle *= AngleToRadian;
    for (int i = 0; i < figure.NumPicks; i++) {
        RotatePick(figure.PicksArray[i], rotateF);
    }

    return SUCCESS;
}

void RotatePick(Pick& pick, RotateFigureArgs rotateP)
{
    double x = pick.X;
    double y = pick.Y;
    double z = pick.Z;

    MoveToCentreRotation(pick, rotateP.CentrePoint);

    pick.X = (x * cos(rotateP.Angle) - y * sin(rotateP.Angle));
    pick.Y = (x * sin(rotateP.Angle) + y * cos(rotateP.Angle));
    pick.Z = z;

    MoveFromCentreRotation(pick, rotateP.CentrePoint);
}

void MoveToCentreRotation(Pick& pick, Point centrePoint)
{
    pick.X -= centrePoint.X;
    pick.Y -= centrePoint.Y;
    pick.Z -= centrePoint.Z;
}

void MoveFromCentreRotation(Pick& pick, Point centrePoint)
{
    pick.X += centrePoint.X;
    pick.Y += centrePoint.Y;
    pick.Z += centrePoint.Z;
}
