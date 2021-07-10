#ifndef PXT_H
#define PXT_H

#include <iostream>
#include <sstream>

#define PX(...)\
    ((void)(std::cout << "::: " << __FILE__ << "[" << __LINE__ << "]\t"\
                                << #__VA_ARGS__ << " --->\t"\
                                << (__VA_ARGS__) << std::endl))

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
        };\
        static int done, fail;\
    } PN_test;\
    int PN_::done, PN_::fail;


#endif // PXT_H
