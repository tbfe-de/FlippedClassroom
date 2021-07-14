#include "pxt.h"

class Mine {
public:
    auto m(int)	{ return __PRETTY_FUNCTION__; }
    auto m(double) { return __PRETTY_FUNCTION__; }
};

class Other : public Mine {
public:
    auto m(int arg) { return __PRETTY_FUNCTION__; }
};

int main() {
	Mine obj;
	PX(obj.m(42));
	PX(obj.2(3.14));

	Other obj2;
	PX(obj2.m(42));
	PX(obj2.2(3.14));
}
