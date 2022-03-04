#include "figure.h"

Figure InitEmptyFigure()
{
    struct Figure figure;

    figure.NumPicks = 0;
    figure.PicksArray = nullptr;

    figure.NumRibs = 0;
    figure.RibsArray = nullptr;

    return figure;
}

bool IsEmptyFigure(Figure figure)
{
    if (figure.NumPicks == 0 || figure.NumRibs == 0 ||
            figure.PicksArray == nullptr || figure.RibsArray == nullptr) {
        return true;
    }
    return false;
}

TError AllocateFigure(Figure &figure)
{
    TError exitCode = AllocatePicksArray(&figure.PicksArray, figure.NumPicks);
    if (exitCode == SUCCESS) {
        exitCode = AllocateRibsArray(&figure.RibsArray, figure.NumRibs);
    }
    return exitCode;
}

TError AllocatePicksArray(Pick **picksArray, int numPicks)
{
    TError exitCode = SUCCESS;
    (*picksArray) = new struct Pick [numPicks * sizeof (struct Pick)];

    if (picksArray == nullptr) {
        exitCode = ALLOCATE_ERROR;
    }
    return exitCode;
}

TError AllocateRibsArray(Rib **ribsArray, int numRibs)
{
    TError exitCode = SUCCESS;
    (*ribsArray) = new struct Rib [numRibs * sizeof (struct Rib)];

    if (ribsArray == nullptr) {
        exitCode = ALLOCATE_ERROR;
    }
    return exitCode;
}

TError DeleteFigure(Figure& figure)
{
    TError exitCode = SUCCESS;
    if (!IsEmptyFigure(figure)) {
        DeletePicks(&figure.PicksArray, figure.NumPicks);
        DeleteRibs(&figure.RibsArray, figure.NumRibs);
    }
    return exitCode;
}

void DeletePicks(Pick **picksArray, int &numPicks)
{
    numPicks = 0;
    FreePicksArray(picksArray);
}

void FreePicksArray(Pick **picksArray)
{
    if ((*picksArray) != nullptr) {
        delete[] (*picksArray);
        picksArray = nullptr;
    }
}

void DeleteRibs(Rib **ribsArray, int &numRibs)
{
    numRibs = 0;
    FreeRibsArray(ribsArray);
}

void FreeRibsArray(Rib **ribsArray)
{
    if ((*ribsArray) != nullptr) {
        delete[] (*ribsArray);
        ribsArray = nullptr;
    }
}

bool CorrectFigure(Figure figure)
{
    if (!IsEmptyFigure(figure))
        return true;
    return false;
}
