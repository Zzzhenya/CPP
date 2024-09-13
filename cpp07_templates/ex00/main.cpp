#include <iostream>
#include <string>
#include <cstring>
template <typename T>void swap(T &x, T &y)
{
	T temp = T(x);
	x = y;
	y = temp;
}

// template <typename T>void swap(T *x, T *y)
// {
// 	std::cout << "*" << std::endl;
// 	T temp = *x;
// 	*x = *y;
// 	*y = temp;
// }

// void	swap(char *x, char *y)
// {
// 	char temp = *x;
// 	*x = *y;
// 	*y = temp;
// }

void swap_tests(void)
{
std::cout << std::endl << "=========== int ============" << std::endl << std::endl;
	{
		int x = 2; int y = 6;
		std::cout << "x: " << x << " | y: " << y << std::endl;
		swap <int> (x, y);
		std::cout << "x: " << x << " | y: " << y << std::endl;
	}
	std::cout << std::endl << "=========== float ==========" << std::endl << std::endl;
	{
		float x = 2.23f; float y = 6.98f;
		std::cout << "x: " << x << " | y: " << y << std::endl;
		swap <float > (x, y);
		std::cout << "x: " << x << " | y: " << y << std::endl;	
	}
	std::cout << std::endl << "=========== double ==========" << std::endl << std::endl;
	{
		double x = 2.232; double y = 6.982;
		std::cout << "x: " << x << " | y: " << y << std::endl;
		swap <double> (x, y);
		std::cout << "x: " << x << " | y: " << y << std::endl;	
	}
	std::cout << std::endl << "=========== char * ==========" << std::endl << std::endl;
	{
		// char x[1] = {'A'}; char y[1] = {'B'};
		// swap <char [1]> (x, y);
		char *x = new char('A'); char *y = new char('B');
		std::cout << "x: " << (void *)&x << " - " << x << " | y: " << (void *)&y << " - " << y << std::endl;
		swap <char *> (x, y);
		std::cout << "x: " << (void *)&x << " - " << x << " | y: " << (void *)&y << " - " << y << std::endl;
		delete x; delete y;
	}
	// std::cout << "===========std::string *==========" << std::endl;
	// {
	// 	std::string *x = new std::string("Hello"); 
	// 	std::string *y = new std::string("World");
	// 	std::cout << "x: " << x << " - " << *x << " | y: " << y << " - " << *y << std::endl;
	// 	swap <std::string *> (x, y);
	// 	std::cout << "x: " << x << " - " << *x << " | y: " << y << " - " << *y << std::endl;
	// 	delete x; delete y;
	// }
	std::cout << std::endl << "=========== char ============" << std::endl << std::endl;
	{
		char x = 'A'; char y = 'B';
		std::cout << "x: " << (void *)&x << " - "  << x << " | y: " << (void *)&y << " - "  << y << std::endl;
		swap <char > (x, y);
		std::cout << "x: " << (void *)&x << " - "  << x << " | y: " << (void *)&y << " - "   << y << std::endl;
	}
	std::cout << std::endl << "=========== int =============" << std::endl << std::endl;
	{
		int x[1] = {2}; int y[1] = {6};
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - " << *y << std::endl;
		swap <int> (*x, *y);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - " << *y << std::endl;
	}
	std::cout << std::endl << "=========== int * ===========" << std::endl << std::endl;
	{
		//int x[1] = {2}; int y[1] = {6};
		int *x = new int(2); int *y = new int(6);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - " << *y << std::endl;
		swap <int *> (x, y);
		std::cout << "x: " << x << " - " << *x << " | y: " << y << " - " << *y << std::endl;
		delete x; delete y;
	}
	std::cout << std::endl << "=== char *, std::string =====" << std::endl << std::endl;
	{
		std::string str1 = "Hello";
		char *x = new char (str1.length() + 1);
		std::strcpy (x, str1.c_str());
		std::string str2 = "World";
		char *y = new char (str2.length() + 1);
		std::strcpy (y, str2.c_str());
		std::cout << "x: " << (void *)&x << " - " << x << " | y: " << (void *)&y << " - " << y << std::endl;
		swap <char *> (x, y);
		std::cout << "x: " << (void *)&x << " - " << x << " | y: " << (void *)&y << " - " << y << std::endl;
		delete x; delete y;
	}
	std::cout << std::endl;
}

int main(void)
{
	std::cout << std::endl << "============================\tswap\t====" << std::endl;
	swap_tests();
	
	return (0);
}
