#include "pxt.h"

PN_(Developing VF_Array – Testing STEP 2)

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

    /*TBD*/

  } // --------------------------------------------------
}
