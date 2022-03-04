#ifndef SCALEFIGURE_H
#define SCALEFIGURE_H

#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "figure.h"

struct ScaleFigureArgs
{
    double Kx, Ky, Kz;
    Point CentrePoint;
};

TError ScaleFigure(Figure &figure, ScaleFigureArgs scaleF);
void ScalePick(Pick &pick, ScaleFigureArgs scaleP);
void MoveToCentreScaling(Pick &pick, Point centrePoint);
void MoveFromCentreScaling(Pick &pick, Point centrePoint);

#endif // SCALEFIGURE_H
