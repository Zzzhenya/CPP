#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <exception>
# include <string>
# include <utility>
# include <map>

# define DATABASE_NAME "data.csv"

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		~BitcoinExchange(void);
		// BitcoinExchange(const BitcoinExchange &other);
		// BitcoinExchange &operator=(const BitcoinExchange &other);
		void 	print_dbmap(void);

	//private:
		std::map<std::string,std::string> dbmap;
};

#endif
