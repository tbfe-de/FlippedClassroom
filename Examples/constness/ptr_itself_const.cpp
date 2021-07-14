int main() {
    char greet[] = "hello, world";
    char* const cp = greet;
//  char *const cp = greet;
//  char *cp const = greet; // <---- ???? 
    *cp = 'H';      // does this compile?
    ++cp;           // and this?
}

