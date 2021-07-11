#include "pxt.h"

PN_(Developing `class NamedValue` (Type Conversion Test));

#include "NamedValue.h"

int main() {
    NamedValue t{"height", 12};
    PX_("height", t.name());
    PX_("12", t.value());
    PX_("height: 12", t);
    t = -1;                
    PX_("height", t.name());
    PX_("-1", t.value());
    PX_("height: -1", t);
    t = 0;
    PX_("height: 0", t);
    NamedValue u{"width", 20};
    NamedValue v{"area", 100};
    t = v / u;
    PX_("height: 5", t);
    PX_("width: 20", u);
    PX_("area: 100", v);
    u += 10;
    v = t * u;
    PX_("height: 5", t);
    PX_("width: 30", u);
    PX_("area: 150", v);

    t -= 2;
    PX_("height: 3", t);
    t *= 4;
    PX_("height: 12", t);
    t /= 6;
    PX_("height: 2", t);
}
