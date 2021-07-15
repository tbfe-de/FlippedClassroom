#include "pxt.h"

PN_(Developing VF_Array – Testing STEP 5)

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
    v.push_back(31);	PX_("31",   v.back());
    v.push_back(32);	PX_("32",   v.back());

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
			PX_("false",  v.empty());

    auto const& v2{v};	PX_("false",  v2.empty());
			PX_("2",      v2.size());

    vf_array<bool, 2> const v3{};
			PX_("0",      v3.size());
			PX_("true",   v3.empty());
  } // --------------------------------------------------

  { // ------------------------------------ step_04 tests
    vf_array<int, 10> v{};
    PX_("true", v.begin() == v.end());
    PX_("true", v.cbegin() == v.cend());

    v.push_back(31);
    PX_("31", *v.begin());
    PX_("31", *v.cbegin());
    PX_("1", v.end() - v.begin());
    PX_("1", v.cend() - v.cbegin());

    v.push_back(32);
    PX_("31", *v.begin());	// the first element
    PX_("31", *v.cbegin());	// should NOT change
    PX_("2", v.end() - v.begin());
    PX_("2", v.cend() - v.cbegin());

    auto p = v.begin();
    PT_("int&", decltype(*p));

    auto const& v2{v};
//  PX_("31", *v.begin()); // <----- should NOT compile
    PX_("31", *v2.cbegin());
    PX_("2", v.cend() - v.cbegin());

    auto p2 = v2.cbegin();
    PT_("int const&", decltype(*p2));
  } // --------------------------------------------------

  
  { // ------------------------------------ step_05 tests

    /*TBD*/

  }
}
