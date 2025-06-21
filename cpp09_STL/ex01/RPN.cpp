#include "RPN.hpp"

bool RPN::processString(char *arg)
{
	if (!arg || arg[0] == '\0')
	{
		message("Null or empty input");
	 	return (false);
	}

	std::string str(arg);

	message(str);
	std::istringstream ss(str);

	// char curr;
	std::string curr;
	/*
	reads until whitespace is reached or fails, 
	also trims whitespaces from begining
	when string is empty or consists of only white spaces -> fails
	*/
	while (ss >> curr)
	{
		if (ss.fail())
			message("stringstream failed");
		else
			message(curr);
	}
	return (true);
}

