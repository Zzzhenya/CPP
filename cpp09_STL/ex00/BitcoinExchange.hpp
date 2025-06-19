#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <exception>
# include <string>
# include <utility>
# include <map>
# include <sstream>

# ifndef DATABASE_NAME
#  define DATABASE_NAME "data123.csv"
# endif
# define debug(x) (std::cerr << "\033[0;31m" << __FUNCTION__ << ": " <<__LINE__ << ":\t" << x << "\033[0m" << std::endl)
# define message(x) (std::cout << "Error" << ":\t" << x  << std::endl)
# define warning(x) (std::cout << "Warning" << ": " << x  << std::endl)
// # define DATABASE_NAME "empty_line.csv"

class BitcoinExchange
{
	public:
		bool initDB(void);
		bool runFile(char *str);
		void Query(std::string date, std::string amount);

		void 	print_dbmap(void);
		void 	print_qlist(void);

		BitcoinExchange(void);
		~BitcoinExchange(void);

	private:

		void runQuery(int no, std::string str);
		bool validateDB(void);
		bool validateFile(char *str);
		int read_csv_lines(std::fstream &db);

		std::map<int,std::string> 			qlist;
		std::map<std::string,std::string> 	dbmap;

		// BitcoinExchange(const BitcoinExchange &other);
		// BitcoinExchange &operator=(const BitcoinExchange &other);
};

#endif
