#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <cctype>


# define message(x) (std::cout << x  << std::endl)
# define error(x) (std::cout << x  << std::endl)

class RPN
{
public:
	bool processString(char *str);

	std::stack<double> stk;

private:

};

#endif
