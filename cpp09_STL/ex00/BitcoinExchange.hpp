#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <exception>
# include <string>
# include <utility>
# include <map>

# define DATABASE_NAME "data123.csv"
// # define DATABASE_NAME "empty_line.csv"

class BitcoinExchange
{
	public:
		bool initDB(void);

		void Query(std::string date, std::string amount);

		int read_csv_lines(std::fstream &db);

		// bool closeFile(std::fstream &file)
		
		bool runFile(char *str);
		// 
		
		// validateQuery(void);

		void 	print_dbmap(void);
		void 	print_qlist(void);

		BitcoinExchange(void);
		~BitcoinExchange(void);

		std::map<std::string,std::string> dbmap;
		std::map<int,std::string> 			qlist;
		//private:
	private:
		void runQuery(int no, std::string str);
		bool validateDB(void);
		bool validateFile(char *str);
		//void runQuery(void);

		// BitcoinExchange(const BitcoinExchange &other);
		// BitcoinExchange &operator=(const BitcoinExchange &other);
};

#endif
