#include "pxt.h"

PN_(Developing VF_Array – std::vector reference tests);

#include <iostream>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& lhs, std::vector<T> const &rhs) {
    for (auto const& e : rhs) {
        lhs << e << ' ';
    }
    return lhs;
}

template<typename T>
auto is_const(T&) { return "T ref"; }

template<typename T>
auto is_const(T const&) { return "const T ref"; }

int main() {
    std::cout.setf(std::ios::boolalpha);
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);

  { // ------------------------------------ step_01 tests
    std::vector<int> v{};
    PX_("4611686018427387903",		v.max_size());
  } // --------------------------------------------------

  { // ------------------------------------ step_02 tests
    std::vector<int> v{};
    v.push_back(31);	PX_("31",	v.back());
    v.push_back(32);	PX_("32",	v.back());

    std::vector<double> v2{};
    v2.push_back(1.25);	PX_("1.25", 	v2.back());
  } // --------------------------------------------------

  { // ------------------------------------ step_03 tests
    std::vector<int> v{};
			PX_("0",	v.size());
			PX_("true",	v.empty());
    v.push_back(31);	PX_("1",	v.size());
			PX_("false",	v.empty());
    v.push_back(32);	PX_("2",	v.size());
			PX_("false",	v.empty());
  } // --------------------------------------------------

  { // ------------------------------------ step_04 tests
    std::vector<int> v{};
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
    std::vector<int> v{};

    PT_("int&",		decltype(v.back()));
//  PT_("",		decltype(v.begin()));
//  PT_("",		decltype(v.end()));
//  PT_("",		decltype(v.cbegin()));
//  PT_("",		decltype(v.cend()));
  } // --------------------------------------------------

  { // ------------------------------------ step_06 tests
    std::vector<int> v0{};          PX_("0", v0.size());
//  std::vector<int> v1{1, 2, 3};   PX_("1", v1.size());
//  std::vector<int> v2{2, 3, 4};   PX_("2", v2.size());
    std::vector<int> v3{4, 5, 6};   PX_("3", v3.size());
    std::vector<int> v4{5, 6, 7};   PX_("3", v4.size());
    std::vector<int> v5{6, 7, 8};   PX_("3", v5.size());
    std::vector<int> v6{7, 8, 9};   PX_("3", v6.size());
  } // --------------------------------------------------

  { // ------------------------------------ step_07 tests
    std::vector<int> v0{};          PX_("",         v0);
//  std::vector<int> v1{1, 2, 3};   PX_("1 ",       v1);
//  std::vector<int> v2{2, 3, 4};   PX_("2 3 ",     v2);
    std::vector<int> v3{4, 5, 6};   PX_("4 5 6 ",   v3);
    std::vector<int> v4{5, 6, 7};   PX_("5 6 7 ",   v4);
    std::vector<int> v5{6, 7, 8};   PX_("6 7 8 ",   v5);
    std::vector<int> v6{7, 8, 9};   PX_("7 8 9 ",   v6);
   } // --------------------------------------------------

  { // ------------------------------------ step_08 tests
    std::vector<int> v{};
    PX_("T ref",  	is_const(    v.back()	    ));
    PX_("T ref", 	is_const(    *v.begin()	    ));
    PX_("const T ref", 	is_const(    *v.cbegin()    ));
    PX_("T ref", 	is_const(    *v.end()	    ));
    PX_("const T ref", 	is_const(    *v.cend()      ));

    std::vector<int> const cv{};
    PX_("const T ref",  is_const(    cv.back()	    ));
    PX_("const T ref", 	is_const(    *cv.begin()    ));
    PX_("const T ref", 	is_const(    *cv.cbegin()   ));
    PX_("const T ref", 	is_const(    *cv.end()	    ));
    PX_("const T ref", 	is_const(    *cv.cend()	    ));
  } // --------------------------------------------------

  { // ------------------------------------ step_09 tests
    std::vector<int> v{4, 5, 6};
    PX_("T ref", is_const(v[0]));	PX_("4", v[0]);
					PX_("5", v[1]);
					PX_("6", v[2]);
    PX_("T ref", is_const(v.at(0)));	PX_("4", v.at(0));
                                        PX_("5", v.at(1));
                                        PX_("6", v.at(2));
    std::vector<int> const cv{0};
    PX_("const T ref", is_const(cv[0]));
    PX_("const T ref", is_const(cv.at(0)));
  } // --------------------------------------------------
}
