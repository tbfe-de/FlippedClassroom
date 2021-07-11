#include "pxt.h"

PN_(Developing `class NamedValue` (Getter Test));

#include "NamedValue.h"

int main() {
    NamedValue t{"height", 12};
    PX_("height", t.name());
    PX_("12", t.value());
//  t.set(-1);                
    PX_("height", t.name());
    PX_("-1", t.value());
}
