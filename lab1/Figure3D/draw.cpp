#include "draw.h"

void Draw(struct Figure figure, struct DrawFigure drawF)
{
    Line *line = new Line(100, 200, -30, -49, "black");
    drawF.scene->addItem(line);
}
