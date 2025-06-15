#include "BitcoinExchange.hpp"

#define debug(x) (std::cerr << "\033[0;31m" << __FUNCTION__ << ": " <<__LINE__ << ":\t" << x << "\033[0m" << std::endl)
#define message(x) (std::cout << "Error" << ":\t" << x  << std::endl)

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
	int row = 0;

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
			{
				if (row > 0)
					dbmap.insert(std::pair<std::string,std::string>(first,second));
			}
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
				message("File open error" << DATABASE_NAME);
			if (db.bad())
				message("badbit is set: " << DATABASE_NAME);
			if (db.fail())
				message(std::strerror(errno));
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

bool validateDate(std::string date)
{
	(void)date;
	return (true);
}

bool validateAmount(std::string amount)
{
	//(void)date;
	if (amount.length() == 0)
		return (false);
	try
	{
		float ret = std::atof(amount.c_str());
		if (ret < 0 )
		{
			message("amount too low");
			return false;
		}
		else if (ret > 1000)
		{
			message("amount too high");
			return (false);
		}
		return (true);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (false);
}

bool validateRate(std::string val)
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
		date = validateDate(it->first);
		val = validateRate(it->second);
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
	debug("openFile");
	try
	{
		std::fstream q(file, std::ios::in);
		if (!q.is_open() || q.bad() || q.fail())
		{
			if (!q.is_open())
				message("file open error: " << file);
			if (q.bad())
				message("badbit is set: " << file);
			if (q.fail())
				message(std::strerror(errno));
			return (false);
		}
		debug("storeFile");
		std::string line;
		int row = 0;
		while (std::getline(q, line))
		{
			if (row > 0)
				qlist.insert(std::pair<int,std::string>(row,line));
			row++;
		}
		debug("closeFile");
		q.close();
		return (true);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << file << std::endl;
	}
	// (void)file;
	return (false);
}

void BitcoinExchange::Query(std::string date, std::string amount)
{
	std::map<std::string,std::string>::iterator it = dbmap.find(date);
	if (it == dbmap.end())
	{
		it = dbmap.lower_bound(date);
		it --;
	}
	//debug(it->second);
	std::cout << date << "\t:" << amount << "\t* " \
	<< it->second << "\t=\t"\
	<<  (std::atof(amount.c_str())) * (std::atof(it->second.c_str())) << std::endl;
}

void BitcoinExchange::runQuery(int no, std::string str)
{
	//debug("runQuery");
	//message(no << " " << str);
	(void)no;
	std::string::size_type	ret = str.find(" | ");
	std::string first; std::string second;

	if (ret == std::string::npos)
		message("bad input => " << str);
	else
	{
		if (ret + 3 != std::string::npos)
		{
			first = str.substr(0, ret);
			second = str.substr(ret + 3, str.length() - 1);
			bool date = validateDate(first);
			bool amount = validateAmount(second);
			if (!date)
				message("bad input => " << first);
			if (date && amount)
				Query(first, second);
		}
		else
			message("wrong format");
	}
	// std::istringstream iss(str);

	// getline()
	
}

bool BitcoinExchange::runFile(char *str)
{
	if (!validateFile(str))
		return (false);
	if (qlist.empty()){
		message("text file empty"); return (false);
	}
	for (std::map<int,std::string>::iterator it = qlist.begin(); it != qlist.end(); it++)
	{
		runQuery(it->first, it->second);
		//std::cout << it->first << " : " << it->second << std::endl;
	}
	return (true);
}

void BitcoinExchange::print_qlist(void)
{
	if (qlist.empty())
		std::cout << "empty" << std::endl;
	else
	{
		for (std::map<int,std::string>::iterator it = qlist.begin(); it != qlist.end(); it++)
			std::cout << it->first << " : " << it->second << std::endl;
	}
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

