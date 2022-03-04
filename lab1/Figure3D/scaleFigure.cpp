#include "scaleFigure.h"

TError ScaleFigure(Figure& figure, ScaleFigureArgs scaleF)
{
    if (IsEmptyFigure(figure)) {
        return EMPTY_FIGURE;
    }

    for (int i = 0; i < figure.NumPicks; i++) {
        ScalePick(figure.PicksArray[i], scaleF);
    }

    return SUCCESS;
}

void ScalePick(Pick& pick, ScaleFigureArgs scaleP)
{
    MoveToCentreScaling(pick, scaleP.CentrePoint);

    pick.X *= scaleP.Kx;
    pick.Y *= scaleP.Ky;
    pick.Z *= scaleP.Kz;

    MoveFromCentreScaling(pick, scaleP.CentrePoint);
}

void MoveToCentreScaling(Pick& pick, Point centrePoint)
{
    pick.X -= centrePoint.X;
    pick.Y -= centrePoint.Y;
    pick.Z -= centrePoint.Z;
}

void MoveFromCentreScaling(Pick& pick, Point centrePoint)
{
    pick.X += centrePoint.X;
    pick.Y += centrePoint.Y;
    pick.Z += centrePoint.Z;
}

