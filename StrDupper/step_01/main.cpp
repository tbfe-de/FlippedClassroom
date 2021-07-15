#include <cstring>
#include <iostream>

class StrDupper {
	static int allocated_;
public:
	static char const* copy(char const *s) {
		auto const sz = std::strlen(s);
		auto const result = new char[sz+1];
		++allocated_;
		std::strncpy(result, s, sz)[sz] = '\0';
		return result;
	}
	static void free(char const* s) {
		--allocated_;
		delete[] s;
	}
	static int allocated() {
		return allocated_;
	}
};
int StrDupper::allocated_ = 0;

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
	else if (StrDupper::allocated() < 0) {
		std::cout << "duplicated free" << std::endl;
	}
	else {
		std::cout << "StrDupper says: OK" << std::endl;
	}
}
