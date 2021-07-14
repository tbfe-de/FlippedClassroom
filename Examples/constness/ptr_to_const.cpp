int main() {
    const char *greet = "hello, world";
//  const char* greet = "hello, world"; // alternatively
//  char const* greet = "hello, world"; // alternatively
    *greet = 'H';   // will this compile?
    ++greet;        // and this?
}
