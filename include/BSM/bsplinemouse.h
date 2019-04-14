#ifndef BSPLINEMOUSE_H
#define BSPLINEMOUSE_H

#include "bsplinemouse_global.h"
#include "vec2.h"

namespace BSplineMouse
{
    Vec2 moveMouseTo(Vec2 mousePos);

    double randRange(double min, double max);
    void leftMouseClick();

    void rightMouseClick();

    void scrollMouseClick();
}

#endif // BSPLINEMOUSE_H
