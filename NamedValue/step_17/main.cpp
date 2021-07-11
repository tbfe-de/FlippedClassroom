#include "pxt.h"

PN_(Developing `class NamedValue` (Test StrDupper Helper));

#include "NamedValue.h"

int main() {
    { // -------------------------------START nested block
    NamedValue<int> t{"height", 12};
    PX_("height", t.name());
    PX_("12", t.value());
    PX_("height: 12", t);
    t = -1;                
    PX_("height", t.name());
    PX_("-1", t.value());
    PX_("height: -1", t);
    t = 0;
    PX_("height: 0", t);
    NamedValue<int> u{"width", 20};
    NamedValue<int> v{"area", 100};
    t = v / u;
    PX_("height: 5", t);
    PX_("width: 20", u);
    PX_("area: 100", v);
    u += 10;
    v = t * u;
    PX_("height: 5", t);
    PX_("width: 30", u);
    PX_("area: 150", v);

    PX_("height: 0", t = 0);
    PX_("height: 3", t += 3);
    PX_("height: 1", t -= 2);
    PX_("height: 3", t *= 3);
    PX_("height: 0", t /= 4); // actually 0.75 but truncated

    PX_("height: 150", t = v);

    NamedValue<int> z{"volume"};
    PX_("volume: 0", z);

    NamedValue<int> x{"averylongnamewithmorethat18chars"};
    PX_("averylongnamewithmorethat18chars: 0", x);

    NamedValue<double> pi{"PI", 3.1415};

    std::cout.precision(7);
    PX_("PI: 3.1415", pi);   
    } // ---------------------------------END nested block
      // (everything allocated inside should be freed now)

}
