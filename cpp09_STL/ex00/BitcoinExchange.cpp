#include "BitcoinExchange.hpp"

void	read_line_by_line(std::fstream &database, std::map<std::string,std::string> &dbmap)
{
	std::string		line;
	std::string		date;
	std::string		value;

	//(void)dbmap;
	bool ret = 0;
	ret = std::getline(database, line);
	while (ret)	
	{
		ret = std::getline(database, date, ',');
		if (ret)
		{
			std::getline(database, value, '\n');
			//dbmap.insert({date, value});
			dbmap.insert(std::pair<std::string,std::string>(date,value));
			// std::cout << date << " : " << value << std::endl;
		}
		// else
		// {
		// 	// empty line at end
		// 	std::cout << date << " : " << std::endl;
		// }
	}
}

int	setup_database(std::map<std::string,std::string> &dbmap)
{
	// try
	// {
		std::fstream database(DATABASE_NAME, std::ios::in);
		database.exceptions(std::fstream::failbit | std::ifstream::badbit);
		read_line_by_line(database, dbmap);
		database.close();
	// }
	// catch (const std::ios_base::failure &fail)
	// {
	// 	std::cerr << "failed to open " << std::string(DATABASE_NAME) << std::endl;
	// 	std::cerr << fail.what() << std::endl;
	// 	return (0);
	// }
	return (1);
}

BitcoinExchange::BitcoinExchange(void)
{
	std::cout << "BitcoinExchange default constructor" << std::endl;
	try
	{
		setup_database(dbmap);
	}
	catch(const std::ios_base::failure &fail)
	{
		throw std::logic_error("exception: failed to open " + std::string(DATABASE_NAME));
		// std::cerr << "failed to open " << std::string(DATABASE_NAME) << std::endl;
		// std::cerr << fail.what() << std::endl;
	}
	// if (!setup_database(dbmap))
	// 	throw std::runtime_error("");
		//std::cout << "Database setup failed" << std::endl;
}

BitcoinExchange::~BitcoinExchange(void)
{
	std::cout << "BitcoinExchange default destructor" << std::endl;
}

void BitcoinExchange::print_dbmap(void)
{
	for (std::map<std::string,std::string>::iterator it = this->dbmap.begin(); it != this->dbmap.end(); it++)
		std::cout << it->first << " : " << it->second << std::endl;
}

