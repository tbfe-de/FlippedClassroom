#include "pxt.h"

PN_(Testing the answer to the "Ultimate Question of Life");

int main() {
   auto const answer = 42u;
   PX_("42", answer);
   PT_("unsigned int", decltype(answer));
}

