#include "loadfigure.h"

TError LoadFigure(struct Figure& figure, struct LoadFigure loadF)
{
    TError ExitCode = LoadArrayFromFile(figure, loadF.filename);
    return ExitCode;
}

TError LoadArrayFromFile(struct Figure& figure, const char *fname)
{
    TError ExitCode = FileCheck(fname);
    if (ExitCode == SUCCESS) {

        FILE *f = fopen(fname, "r");
        fscanf(f, "%d", &figure.NumPoints);

        ExitCode = AllocatePointsArray(figure);
        if (ExitCode == SUCCESS) {
            for (int i = 0; i < figure.NumPoints; i++) {
                struct Point point;
                fscanf(f, "%lf", &(point.x));
                fscanf(f, "%lf", &(point.y));
                fscanf(f, "%lf", &(point.z));
                figure.PointsArray[i] = point;
            }
        }
        fclose(f);
    }
    return ExitCode;
}
