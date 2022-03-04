#ifndef LOADFIGURE_H
#define LOADFIGURE_H

#include "exitcodes.h"
#include "figure.h"
#include <stdio.h>

struct LoadFigure
{
    const char *filename;
};

TError LoadFigure(struct Figure& figure, struct LoadFigure loadF);
TError LoadArrayFromFile(struct Figure& figure, const char *filename);

#endif // LOADFIGURE_H
