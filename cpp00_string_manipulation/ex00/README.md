Namespaces, classes, member functions, stdio streams,
initialization lists, static, const

Object-Oriented Programming.

 C++98 standard.

 class names in UpperCamelCase format
 Files containing class code will
always be named according to the class name

Unless specified otherwise, every output messages must be ended by a new-line
character and displayed to the standard output.


you can’t use any other external library. It means C++11 (and derived
forms) and Boost libraries are forbidden. The following functions are forbidden
too: * printf(), * alloc() and free(). 

unless explicitly stated otherwise, the using namespace <ns_name> and
friend keywords are forbidden

allowed to use the STL in the Module 08 and 09 only. That means:
no Containers (vector/list/map/and so forth) and no Algorithms (anything that
requires to include the <algorithm> header) until then.

When you allocate memory (by using the new
keyword), you must avoid memory leaks.

 Module 02 to Module 09, your classes must be designed in the Orthodox
Canonical Form, except when explicitely stated otherwise.

References: 
https://www.geeksforgeeks.org/static_cast-in-cpp/
https://www.freecodecamp.org/news/c-string-std-string-example-in-cpp/
https://devdocs.io/cpp/string/byte/toupper
https://cplusplus.com/reference/string/string/
https://www.geeksforgeeks.org/pre-increment-and-post-increment-in-c/
https://stackoverflow.com/questions/131241/why-use-iterators-instead-of-array-indices
https://stackoverflow.com/questions/19293642/why-does-the-main-function-work-with-no-return-value