# Developing a Container Class

The goal of this exercise is to develop a container class which similar
to `std::vector` but without using heap memory.

Instead the whole container is allocated
-   on the stack if it's as local object or
-   in the global data area if it's global or `static` in a function or
    class.

(Only as a reminder: `static` for a global variable hasn't a meaning for the
way or where something is allocated but whether it's visible for the linker.
Therefore a **global** `static` object is placed with other global data not
because it is `static` but because it is global.)

Generally speaking the class should combine aspects from
-   std::array (size set at compile time)
-   std::vector (same progamming interface)

The exercise will be run incrementally through several steps, each of
which adds a bit more functionality and some more tests.
