#ifndef MOVEFIGURE_H
#define MOVEFIGURE_H

#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "figure.h"

struct MoveFigureArgs
{
    double Dx;
    double Dy;
    double Dz;
};

TError MoveFigure(Figure &figure, MoveFigureArgs moveF);
void MovePick(Pick &pick, MoveFigureArgs moveP);

#endif // MOVEFIGURE_H
