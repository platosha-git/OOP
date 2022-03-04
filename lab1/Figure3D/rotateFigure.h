#ifndef ROTATEFIGURE_H
#define ROTATEFIGURE_H

#include <stdlib.h>
#include <math.h>
#include <QtMath>
#include <locale.h>
#include "figure.h"

struct RotateFigureArgs
{
    double Angle;
    Point CentrePoint;
};

TError RotateFigure(Figure &figure, RotateFigureArgs rotateF);
void RotatePick(Pick &pick, RotateFigureArgs rotateP);
void MoveToCentreRotation(Pick &pick, Point centrePoint);
void MoveFromCentreRotation(Pick &pick, Point centrePoint);

#endif // ROTATEFIGURE_H
