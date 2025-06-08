#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <exception>
# include <string>
# include <utility>
# include <map>

# define DATABASE_NAME "data123.csv"

class BitcoinExchange
{
	public:
		bool initDB(void);
		// validateDB(void);
		bool runFile(char *str);
		// validateFile(void);
		// runQuery(void);
		// validateQuery(void);

		void 	print_dbmap(void);

		BitcoinExchange(void);
		~BitcoinExchange(void);

	//private:
		std::map<std::string,std::string> dbmap;
	private:

		// BitcoinExchange(const BitcoinExchange &other);
		// BitcoinExchange &operator=(const BitcoinExchange &other);
};

#endif
