Implement indexed-based access via both,
-   `operator[]`
    -   traditionally fast but …
    -	… not check whether index is inside bounds
-   member function `at`
    -   as introduces with C++98
        "somehow" safe out of bounds indices

Understand that what type these two operators return needs the
same solution as the member functions returning iterators and
the member function `back()` had in the previous step.

For the way how you keep make out of bounds indices "somehow"
working chose among the following:
-    "Wrap around" out of bounds indices by taking them modulo
     the current.
-    Throw an appropriate exception from the standard exception
     class hierarchie.
-    Always return the same dummy element put as another member
     in the class `vf_array` for that purpose.

class vf_array {


public:
	.... operator[](std::size_t idx) {  ..... }
	.... at(std::size_t idx) {  ..... }


}

vf_array obj;  

....

obj[8] = ....x
obj.at(8) = .....
