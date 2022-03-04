#include "loadArgs.h"

void LoadArgsToLoadFigure(ArgsManager& args, const char *fname)
{
    args.loadF.filename = fname;
}

void LoadArgsToDrawFigure(ArgsManager& args, QGraphicsScene *scene)
{
    args.drawF.scene = scene;
}

TError LoadArgsToMoveFigure(ArgsManager& args, QString qdx, QString qdy, QString qdz)
{
    std::string dxStr = qdx.toStdString();
    const char *dx = qdx.toStdString().c_str();

    std::string dyStr = qdy.toStdString();
    const char *dy = dyStr.c_str();

    std::string dzStr = qdz.toStdString();
    const char *dz = dzStr.c_str();

    TError ExitCode = CorrectInput(dx, dy, dz);
    if (ExitCode == SUCCESS) {
        setlocale(LC_ALL, "C");
        args.moveF.Dx = atof(dx);
        args.moveF.Dy = atof(dy);
        args.moveF.Dz = atof(dz);
    }
    return ExitCode;
}

TError LoadArgsToScaleFigure(ArgsManager& args, QString qkx, QString qky, QString qkz,
                                                QString qx, QString qy, QString qz)
{
    std::string kxStr = qkx.toStdString();
    const char *kx = kxStr.c_str();

    std::string kyStr = qky.toStdString();
    const char *ky = kyStr.c_str();

    std::string kzStr = qkz.toStdString();
    const char *kz = kzStr.c_str();

    TError ExitCode = CorrectInput(kx, ky, kz);
    if (ExitCode == SUCCESS) {

        std::string xStr = qx.toStdString();
        const char *x = xStr.c_str();
        std::string yStr = qy.toStdString();
        const char *y = yStr.c_str();
        std::string zStr = qz.toStdString();
        const char *z = zStr.c_str();

        ExitCode = CorrectInput(x, y, z);
        if (ExitCode == SUCCESS) {
            setlocale(LC_ALL, "C");
            args.scaleF.Kx = atof(kx);
            args.scaleF.Ky = atof(ky);
            args.scaleF.Kz = atof(kz);

            args.scaleF.CentrePoint.X = atof(x);
            args.scaleF.CentrePoint.Y = atof(y);
            args.scaleF.CentrePoint.Z = atof(z);
        }
    }
    return ExitCode;
}

TError LoadArgsToRotateFigure(ArgsManager& args, QString qangle, QString qx, QString qy, QString qz)
{
    std::string angleStr = qangle.toStdString();
    const char *angle = angleStr.c_str();

    TError ExitCode = CorrectInputAngle(angle);
    if (ExitCode == SUCCESS) {
        std::string xStr = qx.toStdString();
        const char *x = xStr.c_str();

        std::string yStr = qy.toStdString();
        const char *y = yStr.c_str();

        std::string zStr = qz.toStdString();
        const char *z = zStr.c_str();

        ExitCode = CorrectInput(x, y, z);

        if (ExitCode == SUCCESS) {
            setlocale(LC_ALL, "C");
            args.rotateF.Angle = atof(angle);

            args.rotateF.CentrePoint.X = atof(x);
            args.rotateF.CentrePoint.Y = atof(y);
            args.rotateF.CentrePoint.Z = atof(z);
        }
    }
    return ExitCode;
}

void LoadArgsToDeleteFigure(ArgsManager &args)
{
    args.drawF.scene = nullptr;
    args.loadF.filename = nullptr;
}

