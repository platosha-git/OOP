#ifndef FIGURE_H
#define FIGURE_H

#include "correctInput.h"

struct Pick
{
    double X;
    double Y;
    double Z;
};

struct Rib
{
    int Point1;
    int Point2;
};

struct Figure
{
    int NumPicks;
    Pick *PicksArray;

    int NumRibs;
    Rib *RibsArray;
};

struct Point
{
    double X;
    double Y;
    double Z;
};

TError AllocateFigure(Figure &figure);
TError AllocatePicksArray(Pick **picksArray, int numPicks);
TError AllocateRibsArray(Rib **ribsArray, int numRibs);

TError DeleteFigure(Figure& figure);
void DeletePicks(Pick **picksArray, int &numPicks);
void DeleteRibs(Rib **ribsArray, int &numRibs);
void FreePicksArray(Pick **picksArray);
void FreeRibsArray(Rib **ribsArray);

struct Figure InitEmptyFigure();
bool IsEmptyFigure(Figure figure);
bool CorrectFigure(Figure figure);

#endif // FIGURE_H
