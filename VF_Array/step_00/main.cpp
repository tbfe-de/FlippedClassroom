#include "pxt.h"

PN_(Developing VF_Array – std::vector reference tests);

#include <vector>

int main() {
    std::cout.setf(std::ios::boolalpha);
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);

  { // ------------------------------------ step_01 tests
    std::vector<int> v{};
    PX_("4611686018427387903", v.max_size());
  } // --------------------------------------------------

  { // ------------------------------------ step_02 tests
    std::vector<int> v{};
    v.push_back(31);	PX_("31", v.back());
    v.push_back(32);	PX_("32", v.back());

    std::vector<double> v2{};
    v2.push_back(1.25);	PX_("1.25", v2.back());
  } // --------------------------------------------------
}
