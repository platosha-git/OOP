#ifndef GETFIGURE_H
#define GETFIGURE_H

#include "exitcodes.h"
#include "figure.h"

struct LoadFigure
{
    const char *filename;
};

TError GetFigure(struct Figure& figure, struct LoadFigure loadF);
TError GetArrayFromFile(struct Figure& figure, char *filename);

#endif // GETFIGURE_H
