#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <map>

#define DATABASE_NAME "data.csv"

/*
 * 	- check all dates of the timeframe are included
 * 		- if date not available ; add date
 * 	- check all dates for exchange rates
 * 		- if no exchange rate, get previous
 * 		- repeat until all dates have rates and no nulls
 * 			- count the number of prev day fills
 * 			- fill
*/


void	read_line_by_line(std::fstream &database, std::map<std::string,std::string> &dbmap)
{
	std::string		line;

	(void)dbmap;
	while (!database.eof())	
	{
		std::getline(database, line);
		// if (database.eof() && line.length() == 0)
		// 	break;
		// if (has_needle(line, find))
		// 	line = replace_needle(line, find, replace);
		//outfile << line << "\n";
		std::cout << line << std::endl;
		// if (database.eof())
		// 	break;
	}
}

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

int	setup_database(std::map<std::string,std::string> &dbmap)
{
	// try
	// {
		std::fstream database(DATABASE_NAME, std::ios::in);
		//database.exceptions(std::fstream::failbit | std::ifstream::badbit);
		read_line_by_line(database, dbmap);
		database.close();
	// }
	// catch (const std::ios_base::failure &fail)
	// {
	// 	std::cerr << "failed to open " << std::string(DATABASE_NAME) << std::endl;
	// 	std::cerr << fail.what() << std::endl;
	// }
	return (1);
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
int main(void)
{
	std::map<std::string,std::string> dbmap;
	if (!setup_database(dbmap))
		return (1);
	return (0);
}
