#include <iomanip>

#include "pxt.h"
#include "Clock.h"

PN_(Testing the Clock);

using namespace clock1;

std::ostream& operator<<(std::ostream& lhs, Clock const& rhs) {
    std::ostream os{lhs.rdbuf()};
    os.fill('0');
    os << rhs.getHours()
               << ':' << std::setw(2) << rhs.getMinutes()
               << ':' << std::setw(2) << rhs.getSeconds();
    return lhs;
}

int main() {
    Clock clk;              PX_("0:00:00", clk);
    clk.stepSeconds();      PX_("0:00:01", clk);
    clk.stepSeconds(58);    PX_("0:00:59", clk);
    clk.stepSeconds(2);     PX_("0:01:01", clk);
    clk.stepSeconds(58);    PX_("0:01:59", clk);
    clk.stepMinutes(58);    PX_("0:59:59", clk);
    clk.stepSeconds(1);     PX_("1:00:00", clk);
}
