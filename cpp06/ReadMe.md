
# C++ casts

	* static - convert between related types


	#include <typeinfo>
	// cast
		static_cast <double> (num);
	// gettype
		typeid(num).name();


	* dynamic - to down cast
	// cast
		dynamic_cats <new_type> (num);

	* const - modify const/volatile nature of a variable to temporarily modify
	// cast
		ptr -  Pointer to a const int
		int* nonConstPtr = const_cast<int*>(ptr);

	* reinterpret - convert a pointer to another type of pointer
	// cast
		ptr - pointer to an int
		char* charPointer = reinterpret_cast<char*>(ptr);


* https://www.geeksforgeeks.org/casting-operators-in-cpp/

* https://en.cppreference.com/w/cpp/header/string


# Serializing

intptr_t

	signed integer type capable of holding a pointer to void

uintptr_t
	
	unsigned integer type capable of holding a pointer to void


Both have the property 
	that any valid pointer to void can be converted to this type, 
	then converted back to a pointer to void, 
	and the result will compare equal to the original pointer


UINTPTR_MAX
 
	maximum value of std::uintptr_t


serialize 
	reinterpret_cast<uintptr_t>(ptr);

deserialize
	reinterpret_cast<expected pointer type>(uintptr_t variable);


* https://en.cppreference.com/w/cpp/types/integer

* https://stackoverflow.com/questions/1845482/what-is-the-uintptr-t-data-type

* https://pubs.opengroup.org/onlinepubs/000095399/basedefs/stdint.h.html


