#include "pxt.h"

#include "clock1/Clock.h"
#include "clock2/Clock.h"
#include "clock3/Clock.h"

#include <iomanip>

PN_(Testing the Clock);

using namespace clock3; // <----- select the clock to use here

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
