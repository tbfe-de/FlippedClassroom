#include "pxt.h"

PN_(Associate types with their literal suffix);

int main() {
    PT_("int",                  decltype(0)     );
    PT_("unsigned int",         decltype(1u)    );
    PT_("long",                 decltype(2L)    );
//  PT_("..TODO..",             decltype(3uL)   );
//  PT_("..TODO..",             decltype(4LL)   );
//  PT_("..TODO..",             decltype(5uLL)  );
    PT_("double",               decltype(6.)    );
//  PT_("..TODO..",             decltype(7.f)   );
//  PT_("..TODO..",             decltype(8.L)   );
}
