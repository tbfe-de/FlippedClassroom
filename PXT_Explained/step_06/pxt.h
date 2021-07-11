#ifndef PXT_H
#define PXT_H

#include <iostream>
#include <sstream>
#if __has_include(<boost/type_index.hpp>)
#include <boost/type_index.hpp>
#endif

template<typename value_type>
inline
void PN_value(value_type const& expr, std::ostream& os, char const *file, int line, char const* texpr) {
    os << "::: " << file << '[' << line << ']' << '\t' << texpr << " --> "
       << expr << std::endl;
}
#define PX(...)\
    PN_value((__VA_ARGS__), std::cout, __FILE__, __LINE__, #__VA_ARGS__)

template<typename type>
inline
void PN_type(std::ostream& os, char const *file, int line, char const* ttype) {
    os << "::: " << file << '[' << line << ']' << '\t' << ttype << " --> "
       << boost::typeindex::type_id_with_cvr<type>() << std::endl;
}

#define PT(...)\
    PN_type<__VA_ARGS__>(std::cout, __FILE__, __LINE__, #__VA_ARGS__)

#define PX_(expect, ...)\
    do {\
            std::ostringstream result;\
            result.flags(std::cout.flags());\
            result.precision(std::cout.precision());\
            result << (__VA_ARGS__);\
            ++PN_::done;\
            if (result.str() == expect) break;\
            std::cout << "::: " << __FILE__ << '[' << __LINE__ << ']'\
                        << "\t" #__VA_ARGS__ " --> " << result.str()\
                        << "\t!= " << expect << std::endl;\
            ++PN_::fail;\
    } while (false)

#define PT_(expect, ...)\
    do {\
            std::ostringstream result;\
            result.flags(std::cout.flags());\
            result.precision(std::cout.precision());\
            result << boost::typeindex::type_id_with_cvr<__VA_ARGS__>();\
            ++PN_::done;\
            if (result.str() == expect) break;\
            std::cout << "::: " << __FILE__ << '[' << __LINE__ << ']'\
                        << "\t" #__VA_ARGS__ " --> " << result.str()\
                        << "\t!= " << expect << std::endl;\
            ++PN_::fail;\
    } while (false)

#define PN_(...)\
    struct PN_ {\
            PN_() {\
                    std::cout << "... " #__VA_ARGS__ << std::endl;\
            }\
            ~PN_() {\
                    std::cout << "=== " << __FILE__ << ": "\
                                << done << " tests ";\
                    if (fail) std::cout << ", " << fail\
                                        << " FAILED";\
                    else      std::cout << "passed (OK)";\
                    std::cout << std::endl;\
            }\
            static int done, fail;\
    } PN_test;\
    int PN_::done, PN_::fail;

#endif // PXT_H
