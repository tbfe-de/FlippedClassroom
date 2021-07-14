#include "pxt.h"

#include <climits>

int main() {
	PX(CHAR_BIT*(sizeof(unsigned int)));
	PX(CHAR_BIT*(sizeof(1<<20)));
	PX(CHAR_BIT*(sizeof(1<<40)));
	PX(CHAR_BIT*(sizeof(1uLL<<20)));
	PX(CHAR_BIT*(sizeof(1uLL<<40)));
	unsigned int m = 1uLL<<20; // OK (fits in 32 bit)
	unsigned int n{1uLL<<20};  // as before, brace initialization
	unsigned int w = 1uLL<<40; // only warning (for backward compatibility)
     // unsigned int x{1uLL<<40};  // <------- compile error
}
