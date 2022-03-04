#include "getfigure.h"

TError LoadFigure(struct Figure& figure, struct LoadFigure loadF)
{
    TError ExitCode = LoadArrayFromFile(figure, loadF.filename);
    return ExitCode;
}

TError LoadArrayFromFile(struct Figure& figure, const char *filename)
{

}
