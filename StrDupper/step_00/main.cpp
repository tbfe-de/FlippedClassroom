#include <cstring>
#include <iostream>

char const* cstrdup(const char *s) {
	auto const sz = std::strlen(s);
	auto const result = new char[sz+1];
	std::strncpy(result, s, sz)[sz] = '\0';
	return result;
}

char const* foo() {
	char greet[] = "hello, world";
	return cstrdup(greet);
}

int main() {
	auto message = foo();
	// ... maybe more usages of message
	delete[] message;
}
