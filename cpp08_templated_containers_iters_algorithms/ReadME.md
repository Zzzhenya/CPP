
# C++ (c++std=98) Containers

* https://en.cppreference.com/w/cpp/container

## Sequence Containers

	* vector - dynamic continuous array

	* deque - double ended queue

	* list - doubly linked list

## Associative Containers

	* set - collection of unique keys, sorted

	* map - collection of key-value pairs, sorted, keys unique

	* multiset - collection of keys, sorted

	* multimap - collection of key-value pairs, sorted 

## Container adaptors 

* different interface for sequential containers

	* stack - LIFO

	* queue - FIFO

	* priority_queue 

# Vectors

* constructors - c++std=98

	vector();

	explicit vector( const Allocator& alloc );

	explicit vector( size_type count,
	                 const T& value = T(),
	                 const Allocator& alloc = Allocator() );
	
	template< class InputIt >
	vector( InputIt first, InputIt last,
	        const Allocator& alloc = Allocator() );


	vector( const vector& other );

What is a std::Allocator? 


* https://stackoverflow.com/questions/11134497/constant-sized-vector

## Exceptions

* https://en.cppreference.com/w/cpp/error/exception

* https://rollbar.com/blog/error-exceptions-in-c/

## std::stack

template<
    class T,
    class Container = std::deque<T>
> class stack;

template <class Type, class Container = deque<Type> > class stack;