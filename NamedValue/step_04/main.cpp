#include "pxt.h"

PN_(Developing `class NamedValue` (Stream Output Test));

#include "NamedValue.h"

int main() {
    NamedValue t{"height", 12};
    PX_("height", t.name());
    PX_("12", t.value());
  PX_("height: 12", t);
    t.set(-1);                
    PX_("height", t.name());
    PX_("-1", t.value());
  PX_("height: -1", t);
}
