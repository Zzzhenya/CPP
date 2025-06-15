#include <iostream>
#include "BitcoinExchange.hpp"
#include <cstdlib>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		(void)argv;
		std::cout << "./btc file_to_convert(format: date | value )" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange bt;
		if (!bt.initDB())
			return (1);
		// (void)argv;
		bt.runFile(argv[1]);
		//bt.print_dbmap();
		// run_query(argv[1], bt);
	}
	catch (std::exception &e)
	{
		std::cout  << e.what() << std::endl;
		return (1);
	}
	return (0);
}
