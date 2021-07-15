#include "pxt.h"

PN_(Developing VF_Array – Testing STEP 3);

#include "vf_array.h"

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
    v.push_back(31);		PX_("31",   v.back());
    v.push_back(32);		PX_("32",   v.back());

    vf_array<double, 3> v2{};
    v2.push_back(1.25);		PX_("1.25", v2.back());
  } // --------------------------------------------------

  { // ------------------------------------ step_03 tests

    /*TBD*/

  } // --------------------------------------------------
}
