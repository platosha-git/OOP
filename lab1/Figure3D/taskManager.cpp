#include "taskmanager.h"

TError TaskManager(CodeManager code, ArgsManager args)
{
    TError exit_code = SUCCESS;
    switch (code) {
        case load:
        {
            exit_code = LoadFigure(args.figure, args.loadF);
            break;
        }
        /*case carry:
        {
            exit_code = carryover_figure(args.Figure, args.NumPoints, args.dx, args.dy, args.dz);
            break;
        }

        case scale:
        {
            exit_code = scaling_figure(args.Figure, args.NumPoints, args.x, args.y, args.z,
                                                                    args.kx, args.ky, args.kz);
            break;
        }
        case rotation:
        {
            exit_code = rotation_figure(args.Figure, args.NumPoints, args.x, args.y, args.z,
                                                                     args.angle);
            break;
        }
        default:
        {
            exit_code = TASK_CODE_ERROR;
            break;
        }
        */
    }
    return exit_code;
}
