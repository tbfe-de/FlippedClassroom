#include "pxt.h"

PN_(Developing VF_Array – Testing STEP 9)

#include "vf_array.h"

template<typename T>
auto is_const(T&) { return "T ref"; }

template<typename T>
auto is_const(T const&) { return "const T ref"; }

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
    vf_array<int, 10> v{};

    // direct tests (check presence of alias)
    PT_("int",		vf_array<int, 10>::value_type);
    PT_("unsigned long",vf_array<int, 10>::size_type);
    PT_("int*",		vf_array<int, 10>::iterator);
    PT_("int const*",	vf_array<int, 10>::const_iterator);

    // decltype(expression)-based tests
    PT_("int&",			decltype(v.back()));
    PT_("int*",			decltype(v.begin()));
    PT_("int*",			decltype(v.end()));
    PT_("int const*",		decltype(v.cbegin()));
    PT_("int const*",		decltype(v.cend()));

    // and only for completeness
    PT_("unsigned long",	decltype(v.max_size()));
    PT_("unsigned long",	decltype(v.size()));
    PT_("bool",			decltype(v.empty()));
  } // --------------------------------------------------
  
  { // ------------------------------------ step_06 tests
    vf_array<int, 1> v0{};        PX_("0", v0.size());
    vf_array<int, 1> v1{1, 2, 3}; PX_("1", v1.size());
    vf_array<int, 2> v2{2, 3, 4}; PX_("2", v2.size());
    vf_array<int, 3> v3{4, 5, 6}; PX_("3", v3.size());
    vf_array<int, 4> v4{5, 6, 7}; PX_("3", v4.size());
    vf_array<int, 5> v5{6, 7, 8}; PX_("3", v5.size());
    vf_array<int, 6> v6{7, 8, 9}; PX_("3", v6.size());
  } // --------------------------------------------------

  { // ------------------------------------ step_07 tests
    vf_array<int, 1> v0{};          PX_("",         v0);
    vf_array<int, 1> v1{1, 2, 3};   PX_("1 ",       v1);
    vf_array<int, 2> v2{2, 3, 4};   PX_("2 3 ",     v2);
    vf_array<int, 3> v3{4, 5, 6};   PX_("4 5 6 ",   v3);
    vf_array<int, 4> v4{5, 6, 7};   PX_("5 6 7 ",   v4);
    vf_array<int, 5> v5{6, 7, 8};   PX_("6 7 8 ",   v5);
    vf_array<int, 6> v6{7, 8, 9};   PX_("7 8 9 ",   v6);
  } // --------------------------------------------------

  { // ------------------------------------ step_08 tests
    vf_array<int, 1> v{};
    PX_("T ref",  	is_const(    v.back()	    ));
    PX_("T ref", 	is_const(    *v.begin()	    ));
    PX_("const T ref", 	is_const(    *v.cbegin()    ));
    PX_("T ref", 	is_const(    *v.end()	    ));
    PX_("const T ref", 	is_const(    *v.cend()      ));

    const vf_array<int, 1> cv{};
    PX_("const T ref",  is_const(    cv.back()	    ));
    PX_("const T ref", 	is_const(    *cv.begin()    ));
    PX_("const T ref", 	is_const(    *cv.cbegin()   ));
    PX_("const T ref", 	is_const(    *cv.end()	    ));
    PX_("const T ref", 	is_const(    *cv.cend()	    ));
  } // --------------------------------------------------

}
