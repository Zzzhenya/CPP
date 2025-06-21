#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>

# define message(x) (std::cout << x  << std::endl)

class RPN
{
public:
	bool processString(char *str);

	std::stack<int> stk;

private:

};

#endif
