#include <iostream>
#include "BitcoinExchange.hpp"
#include <cstdlib>

// #include <iostream>
// #include <fstream>
// #include <exception>
// #include <string>
// #include <map>

// #define DATABASE_NAME "data.csv"

/*
 * 	- check all dates of the timeframe are included
 * 		- if date not available ; add date
 * 	- check all dates for exchange rates
 * 		- if no exchange rate, get previous
 * 		- repeat until all dates have rates and no nulls
 * 			- count the number of prev day fills
 * 			- fill
*/

// void	split_store(std::string &line, std::map<std::string,std::string> &dbmap)
// {

// }

// void	read_line_by_line(std::fstream &database, std::map<std::string,std::string> &dbmap)
// {
// 	std::string		line;
// 	std::string		date;
// 	std::string		value;

// 	//(void)dbmap;
// 	bool ret = 0;
// 	ret = std::getline(database, line);
// 	while (ret)	
// 	{
// 		ret = std::getline(database, date, ',');
// 		if (ret)
// 		{
// 			std::getline(database, value, '\n');
// 			//dbmap.insert({date, value});
// 			dbmap.insert(std::pair<std::string,std::string>(date,value));
// 			// std::cout << date << " : " << value << std::endl;
// 		}
// 		// else
// 		// {
// 		// 	// empty line at end
// 		// 	std::cout << date << " : " << std::endl;
// 		// }
// 	}
// }

/*
 * Open data.csv
 * Read data into a map - unique keys sorted
 * 	key - date
 * 	value - exchange rate
 * - Manage file open and read errors
 * Parse and correct the data
 *	- check date and rate for format and validity
 * 		- if bad throw errors - unable to convert data type etc.
 * 	- start and end date of database
*/

// int	setup_database(std::map<std::string,std::string> &dbmap)
// {
// 	// try
// 	// {
// 		std::fstream database(DATABASE_NAME, std::ios::in);
// 		//database.exceptions(std::fstream::failbit | std::ifstream::badbit);
// 		read_line_by_line(database, dbmap);
// 		database.close();
// 	// }
// 	// catch (const std::ios_base::failure &fail)
// 	// {
// 	// 	std::cerr << "failed to open " << std::string(DATABASE_NAME) << std::endl;
// 	// 	std::cerr << fail.what() << std::endl;
// 	// }
// 	return (1);
// }

void find_and_calc(BitcoinExchange &bt,std::string &date, std::string &amount)
{
	std::map<std::string,std::string>::iterator it;

	if (*(date.end() - 1) == ' ' )
		date.erase(date.end() - 1);
	if (*(amount.begin()+ 1) == ' ' )
		amount.erase(amount.begin() + 1);
	it = bt.dbmap.find(date);
	if (it == bt.dbmap.end())
	{
		it = bt.dbmap.lower_bound(date);
		it --;
	}
	std::cout << date << "\t:" << amount << "\t* " \
	<< it->second << "\t=\t"\
	<<  (std::atof(amount.c_str())) * (std::atof(it->second.c_str())) << std::endl;
}

/**
 * Open data.csv
 * Read data into a map - unique keys sorted
 * 	key - date
 * 	value - exchange rate
 * - Manage file open and read errors
 * Parse and correct the data
 *	- check date and rate for format and validity
 * 		- if bad throw errors - unable to convert data type etc.
 * 	- start and end date of database
 * 
 * Open and Read file passed as argument
 * 	- throw open/ read errors
 * Check for format	
 * 	- throw errors
 * Go through each line and get date and value
 * Parse the date and value
 * 	- throw errors; Date out of range, negative value, Date bad input, No date, No value
 * For each date, lookup in map, get rate, multiply value by rate and print
 * 	if date not available && date > min_database_date && date < max_database_date
 * 			- go to previous date
 * 			- repeat until a date - value pair is found
*/
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "./btc file_to_convert(in date | value format)" << std::endl;
		return (1);
	}

	std::fstream file(argv[1], std::ios::in);
	

	BitcoinExchange bt;

	//bt.print_dbmap();

	std::string		line;
	std::string		date;
	std::string		amount;

	bool ret = 0;
	ret = std::getline(file, line);
	while (ret)	
	{
		ret = std::getline(file, date, '|');
		if (ret)
		{
			std::getline(file, amount, '\n');
			find_and_calc(bt, date, amount);
			// std::cout << date << " : " << amount << std::endl;
		}
	}
	file.close();

	// std::map<std::string,std::string> dbmap;
	// if (!setup_database(dbmap))
	// 	return (1);
	// for (std::map<std::string,std::string>::iterator it = dbmap.begin(); it != dbmap.end(); it++)
	// 	std::cout << it->first << " : " << it->second << std::endl;
	return (0);
}
