// The macro `PX` is provided as easy mechanism for C++ learners to generate
// output from small demo programs. It evaluates and shows the value of any
// expression given its type has a printable representation.
// (Which is the case for most any type builtin of C++.)
// Besides the evaluation (`expr`) it also shwows it textually (`#expr`).
// This is called "stringizing" as it converts a piece of source code to a
// string literal. That feature is ONLY available for preprocessor macros.
// For further easy reference which piece of code generated the output the
// file name of current translation unit and the line number is shown
// (`__FILE__` and `__LINE__`). This also requires the use of a macro, as if
// it were done in the same way in an inline function the values shown would
// refer to the file and line of its definition, not of its call.
//
#define PX(expr)\
    ((void)(std::cout << '[' << __FILE__ << ':' << __LINE__ << ']' << '\t'\
                      << #expr << '\t' << '-' << '-' << '-' << '>' << ' '\
                      << (expr) << '\n'))
                      