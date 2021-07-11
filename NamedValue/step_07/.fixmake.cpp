#include <unistd.h>
int main() {
    execlp("/usr/bin/ex", "ex", "+%!pr -ti4", "+wq", "Makefile", (const char*)0);
}