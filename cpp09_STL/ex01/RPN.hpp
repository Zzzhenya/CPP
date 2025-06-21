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
		void calcRPN(char *str);

		
		RPN(void);
		~RPN(void);
		RPN(const RPN &rhs);
		RPN &operator=(const RPN &rhs);

	private:
		std::stack<double> stk;

		bool processString(std::string str);
		bool processOperator(char op);
		bool isOperator(char op);
		bool processResult(void);

};

#endif
