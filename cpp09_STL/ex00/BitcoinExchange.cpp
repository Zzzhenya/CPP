#include "BitcoinExchange.hpp"

#define debug(x) (std::cerr << "\033[0;31m" << __FUNCTION__ << ": " <<__LINE__ << ":\t" << x << "\033[0m" << std::endl)
#define message(x) (std::cerr << __FUNCTION__ << ": " <<__LINE__ << ":\t" << x  << std::endl)

BitcoinExchange::BitcoinExchange(void)
{
	debug("BitcoinExchange default constructor");
}

BitcoinExchange::~BitcoinExchange(void)
{
	debug("BitcoinExchange default destructor");
}

int BitcoinExchange::read_csv_lines(std::fstream &db)
{
	std::string				line;
	std::string::size_type	ret;
	int row = 1;

	debug("read_csv_lines");
	while (std::getline(db, line))
	{
		// When a row is empty
		if (line.empty())
			return (row);
		ret = line.find(",");
		// When there is no commas
		if (ret == std::string::npos)
			return (row);
		// std::cout <<row  <<": "<< line << std::endl;
		// If comma is not at the end of the row -> process
		if (ret + 1 != std::string::npos)
		{
			std::string first = line.substr(0, ret);
			std::string second = line.substr(ret + 1, line.length() - 1);
			// std::cout <<row  <<": "<< first << " " << second << std::endl;
			// When there is only one comma, and strings are not empty -> insert to map
			if (first.find(",") != std::string::npos || second.find(",") != std::string::npos)
				return (row);
			else if (first.empty() || second.empty())
				return (row);
			else
				dbmap.insert(std::pair<std::string,std::string>(first,second));
		}
		else
			return (row);
		row++;
	}
	// When file is empty
	if (dbmap.empty())
		return (-1);
	return (0);
}

bool BitcoinExchange::initDB(void)
{
	debug("initDB");
	try
	{
		debug("openFile");
		std::fstream db(DATABASE_NAME, std::ios::in);
		if (!db.is_open() || db.bad() || db.fail())
		{
			if (!db.is_open())
				message("Error opening file: " << DATABASE_NAME);
			if (db.bad())
				message("Error badbit is set: " << DATABASE_NAME);
			if (db.fail())
				message("Error: " << std::strerror(errno));
			return (false);
		}
		debug("closeFile");
		int line  = read_csv_lines(db);
		if (line != 0)
		{
			message("CSV parse error on line: " << line);
			dbmap.clear();
		}
		db.close();
		if (!validateDB())
			return (false);
		return (true);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << DATABASE_NAME << std::endl;
	}
	return (false);
}

bool validate_date(std::string date)
{
	(void)date;
	return (true);
}

bool validate_value(std::string val)
{
	(void)val;
	return (true);
}

bool BitcoinExchange::validateDB(void)
{
	int line = 1;
	if (dbmap.empty())
		return (false);
	for (std::map<std::string,std::string>::iterator it = dbmap.begin(); it != dbmap.end(); it++)
	{
		bool date = 0;
		bool val = 0;
		date = validate_date(it->first);
		val = validate_value(it->second);
		if (!date)
			message("Invalid date on: " << line <<" :"<< it->first);
		if (!val)
			message("Invalid value on: " << line <<" :"<< it->second);
		if (!date || !val)
		{
			dbmap.clear();
			return (false);
		}
	}
	return (true);
}

bool BitcoinExchange::validateFile(char *str)
{
	if (!str || str[0] == '\0')
	{
		message("File name empty");
		return (false);
	}
	std::string file = std::string(str);
	debug("Open file");
	(void)file;
	return (true);
}

void BitcoinExchange::runQuery(void)
{
	debug("Query...");
}

bool BitcoinExchange::runFile(char *str)
{
	if (!validateFile(str))
		return (false);
	runQuery();
	return (true);
}

void BitcoinExchange::print_dbmap(void)
{
	if (dbmap.empty())
		std::cout << "empty" << std::endl;
	else
	{
		for (std::map<std::string,std::string>::iterator it = this->dbmap.begin(); it != this->dbmap.end(); it++)
			std::cout << it->first << " : " << it->second << std::endl;
	}
}

