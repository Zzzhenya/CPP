#include "RPN.hpp"

/*
Here's a step-by-step breakdown:

1. Initialize an empty stack: This stack will hold the operands and intermediate results. 

2. Process the expression from left to right:
	If an operand is encountered: Push it onto the stack. 

	If an operator is encountered:
		Pop the necessary number of operands from the stack (e.g., two operands for a binary operator like addition or multiplication). 
		Perform the operation using the popped operands. 
		Push the result of the operation back onto the stack. 
3. The final result: Once all tokens in the expression have been processed, the value remaining on the stack is the result of the calculation. 


https://medium.com/@danish9980/solving-arithmetic-expressions-with-reverse-polish-notation-rpn-in-python-59c8aeec12a6
https://en.wikipedia.org/wiki/Reverse_Polish_notation#:~:text=In%20reverse%20Polish%20notation%2C%20the,%C3%97%20in%20reverse%20Polish%20notation.
https://en.wikipedia.org/wiki/Shunting_yard_algorithm

*/

bool RPN::processString(char *arg)
{
	if (!arg || arg[0] == '\0')
	{
		error("Error: Null or empty input");
	 	return (false);
	}

	std::string str(arg);
	int loc = 0;

	message(str);
	std::istringstream ss(str);

	// char curr;
	std::string curr;
	/*
	reads until whitespace is reached or fails, 
	also trims whitespaces from begining
	when string is empty or consists of only white spaces -> fails
	when end of string is reached -> fails
	*/
	while (!ss.eof() && ss >> curr)
	{
		if (curr.size() > 1 || curr.size() < 1)
		{
			error("Error: invalid input: " << curr << " : only positive digits and operands" );
			return false;
		}
		else
		{
			if (std::isdigit(curr[0]))
			{
				// push to stack
				stk.push(curr[0] - '0');
				// message("num");
			}
			else if (curr[0] == '+' || curr[0] == '-' || curr[0] == '/' || curr[0] == '*')
			{
				if (stk.size() >= 2)
				{
					double num1 = stk.top();
					stk.pop();
					double num2 = stk.top();
					stk.pop();

					if (curr[0] == '+')
					{
						stk.push(num2+num1);
						// message(stk.top());
					}
					else if (curr[0] == '-')
					{
						stk.push(num2 - num1);
						// message(stk.top());
					}
					else if (curr[0] == '*')
					{
						stk.push(num2*num1);
						// message(stk.top());
					}
					else if (curr[0] == '/')
					{
						if (num1 == 0)
						{
							error("Error: division by 0: ");
							return false;
						}
						stk.push(num2/num1);
						// message(stk.top());
					}
				}
				else
				{
					error("Error: invalid char: " << curr << " : not a RPN");
					return false;
				}
				// message("opr");
			}
			else
			{
				error("Error: invalid input" << curr << ": only digits and +-/* allowed");
				return (false);
			}
		}
		// message(curr);
		loc++;
	}
	// only one string and only whitespaces
	if (ss.fail() && loc == 0)
	{
		error("Error: input consists of only whitespaces");
		return false;
	}

	if (stk.size() == 1)
	{
		message("result: "<< stk.top());
		return (true);
	}
	else
	{
		if (stk.size() == 0)
			error("Error: stack is empty" << " : not a RPN");
		else
			error("Error: too many numbers left in the stack" << " : not a RPN");
		return false;
	}
	// if (ss.eof())
	// 	message("eof");
}

