#include "BitcoinExchange.hpp"

void	read_line_by_line(std::fstream &database, std::map<std::string,std::string> &dbmap)
{

	std::string		line;
	std::string		line2;
	int row = 2;

	while (!database.eof())
	{
		std::getline(database, line, ',');
		// std::cout << row << " "<< line<<"\n";
		std::getline(database, line2, '\n');
		std::cout << row << " "<< line << "+" << line2<<"\n";
		dbmap.insert(std::pair<std::string,std::string>(line,line2));
		row++;
	}

	// std::string		line;
	// std::string		date;
	// std::string		value;

	// int row = 2;

	// //(void)dbmap;
	// bool ret = 0;
	// ret = std::getline(database, line);
	// // while (ret)	
	// while (!database.eof())	
	// {
	// 	// ret = std::getline(database, date, ',');
	// 	std::getline(database, date, ',');
	// 	std::cout << row << " " << ret << " Here\n";
	// 	// if (ret)
	// 	// {
	// 		// ret = 
	// 		std::getline(database, value, '\n');
	// 		//dbmap.insert({date, value});
	// 		dbmap.insert(std::pair<std::string,std::string>(date,value));
	// 		// std::cout << date << " : " << value << std::endl;
	// 	// }
	// 	// else
	// 	// 	break;
	// 	std::cout << row << " " << ret << " Here\n";
	// 	row++;
	// 	// else
	// 	// {
	// 	// 	// empty line at end
	// 	// 	std::cout << date << " : " << std::endl;
	// 	// }
	// }
}

int	setup_database(std::map<std::string,std::string> &dbmap)
{
	try
	{
		std::fstream database(DATABASE_NAME, std::ios::in);
		database.exceptions(std::fstream::failbit | std::ifstream::badbit);
		read_line_by_line(database, dbmap);
		database.close();
	}
	catch (const std::ios_base::failure &fail)
	{
		std::cerr << "failed to open " << std::string(DATABASE_NAME) << std::endl;
		std::cerr << fail.what() << std::endl;
		return (0);
	}
	return (1);
}

BitcoinExchange::BitcoinExchange(void)
{
	std::cout << "BitcoinExchange default constructor" << std::endl;
}

bool BitcoinExchange::initDB(void)
{
	try
	{
		setup_database(dbmap);
		return (true);
	}
	catch(const std::ios_base::failure &fail)
	{
		throw std::logic_error("exception: failed setup " + std::string(DATABASE_NAME));
		// std::cerr << "failed to open " << std::string(DATABASE_NAME) << std::endl;
		// std::cerr << fail.what() << std::endl;
	}
	// if (!setup_database(dbmap))
	// 	throw std::runtime_error("");
		//std::cout << "Database setup failed" << std::endl;
	return (false);
}

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

bool BitcoinExchange::runFile(char *str)
{
	if (!str)
		return (false);
	std::string filename(str);
	std::fstream 	file(filename, std::ios::in);
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
			find_and_calc(*this, date, amount);
		}
	}
	file.close();
	return (true);
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

