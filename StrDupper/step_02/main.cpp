#include <algorithm>
#include <cstring>
#include <iostream>

class StrDupper {
	static std::size_t const MAX = 200;
	static char const* allocated_[MAX];
public:
	static char const* copy(char const *s) {
		auto const sz = std::strlen(s);
		auto const result = new char[sz+1];
		std::strncpy(result, s, sz)[sz] = '\0';
		/*TBD*/
		return result;
	}
	static void free(char const* s) {
		/*TBD*/
		delete[] s;
	}
	static int allocated() {
		return std::count_if(std::begin(allocated_),
	 			     std::end(allocated_),
				     [](auto e) {
					return (e != nullptr);
				     });
	}
};

char const* StrDupper::allocated_[StrDupper::MAX];

char const* foo() {
	char greet[] = "hello, world";
	return StrDupper::copy(greet);
}

int main() {
	auto message = foo();
	// ... maybe more usages of message
	StrDupper::free(message);
	if (StrDupper::allocated() > 0) {
		std::cout << "memory leak" << std::endl;
	}
	else {
		std::cout << "StrDupper says: OK" << std::endl;
	}
}
