#include "pxt.h"

PN_(Developing VF_Array – std::vector reference tests);

#include <vector>

int main() {
    std::cout.setf(std::ios::boolalpha);

  { // ------------------------------------ step_01 tests
    vf_array<int, 10> v{};
    PX_("10", v.max_size());

    vf_array<double, 3> v2{};
    PX_("3", v2.max_size());
  } // --------------------------------------------------

  { // ------------------------------------ step_02 tests
    vf_array<int, 10> v{};
    v.push_back(31);	  PX_("31",   v.back());
    v.push_back(32);	  PX_("32",   v.back());

    vf_array<double, 3> v2{};
    v2.push_back(1.25);	PX_("1.25", v2.back());
  } // --------------------------------------------------

  { // ------------------------------------ step_03 tests
    vf_array<int, 10> v{};
                      PX_("0",      v.size());
                      PX_("true",   v.empty());
    v.push_back(31);	PX_("1",      v.size());
                      PX_("false",  v.empty());
    v.push_back(32);	PX_("2",      v.size());
                      PX_("false",  v.empty())
  } // --------------------------------------------------
}
