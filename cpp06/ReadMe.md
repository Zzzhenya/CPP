
C++ casts

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