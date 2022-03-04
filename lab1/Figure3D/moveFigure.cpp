#include "moveFigure.h"

TError MoveFigure(Figure& figure, MoveFigureArgs moveF)
{
    if (IsEmptyFigure(figure)) {
        return EMPTY_FIGURE;
    }

    for (int i = 0; i < figure.NumPicks; i++) {
        MovePick(figure.PicksArray[i], moveF);
    }

    return SUCCESS;
}

void MovePick(Pick& pick, MoveFigureArgs moveP)
{
    pick.X += moveP.Dx;
    pick.Y += moveP.Dy;
    pick.Z += moveP.Dz;
}
