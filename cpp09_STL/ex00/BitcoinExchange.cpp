#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	debug("BitcoinExchange default constructor");
}

BitcoinExchange::~BitcoinExchange(void)
{
	debug("BitcoinExchange default destructor");
}

bool validateDate(std::string date)
{
	int year;
	int month;
	int day;
	char sep1;
	char sep2;

	std::istringstream ss(date);

	// Spaces are ignored

	if (!(ss>>year)) return (false);

	if (year < 2000 ) return (false); 

	//|| year > current year
	// std::time_t result = std::time(NULL);
	// std::tm *tm = localtime(&result);

	// if (year > tm->tm_year + 1900) return (false);

	if (!(ss>>sep1)) return (false);
	if (sep1 != '-') return (false);

	if (!(ss>>month)) return (false);

	if (month < 1 || month > 12) return (false);

	if (!(ss>>sep2)) return (false);

	if (sep2 != '-') return (false);

	if (!(ss>>day)) return (false);

	if (day < 1 || day > 31) return (false);

	if (month == 4 || month == 6 || month == 9 || month == 11 )
	{
		if (day > 30) return (false);
	}

	if (month == 2)
	{
		bool leapyear = false;
		leapyear =  (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

		if (leapyear && day > 29) return (false);

		if (!leapyear && day > 28) return (false);
	}

	return (true);
}

bool validateAmount(std::string amount)
{
	if (amount.length() == 0)
	{
		message("rate field empty => " << amount);
		return (false);
	}

	std::stringstream ss(amount);
	double value;
	ss >> value;

	if (ss.fail()) 
	{
		message("not a float => " << amount);
		return false;
	}
	if (value < 0)
	{
		message("amount too low => " << amount);
		return false;
	}
	if (value > 1000)
	{
		message("amount too high => " << amount);
		return (false);
	}
	if (value > std::numeric_limits<float>::max())
	{
		message("amount out of range => " << amount);
		return false;
	}

	return (true);
}

bool validateRate(std::string val)
{
	if (val.length() == 0)
	{
		message("rate field empty => " << val);
		return (false);
	}

	std::stringstream ss(val);
	double value;
	ss >> value;
	if (ss.fail()) 
	{
		message("not a float => " << val);
		return false;
	}
	if (value < 0)
	{
		message("amount too low => " << val);
		return false;
	}
	if (value > std::numeric_limits<float>::max())
	{
		message("amount out of range => " << val);
		return false;
	}
	//// if (value == std::numeric_limits<float>::min()) return false; 
	// if (value < std::numeric_limits<float>::lowest()) return false;

	return (true);
}

// Because the stringstream parsing for date only checks for numbers;
// and not the leading zeros and spaces
// Isn't really needed when validating before data insertion
std::string getDate(std::string date)
{
	int year;
	int month;
	int day;
	char sep1;
	char sep2;

	std::istringstream ss(date);

	ss>>year;
	ss>>sep1;
	ss>>month;
	ss>>sep2;
	ss>>day;

	std::stringstream ret;
	ret << year << sep1;
	if (month < 10)
		ret << 0 << month;
	else
		ret << month;
	ret << sep2;
	if (day < 10)
		ret << 0 << day;
	else
		ret << day;
	return (ret.str());
}

int BitcoinExchange::read_csv_lines(std::fstream &db)
{
	std::string				line;
	std::string::size_type	ret;
	int row = 0;
	// int errcount = 0;

	debug("read_csv_lines");
	while (std::getline(db, line))
	{
		// When a row is empty
		if (line.empty())
			return (row + 1);
		ret = line.find(",");
		// When there is no commas
		if (ret == std::string::npos)
			return (row + 1);
		// std::cout <<row  <<": "<< line << std::endl;
		// If comma is not at the end of the row -> process
		if (ret + 1 != std::string::npos)
		{
			std::string first = line.substr(0, ret);
			std::string second = line.substr(ret + 1, line.length() - 1);
			// std::cout <<row  <<": "<< first << " " << second << std::endl;
			// When there is only one comma, and strings are not empty -> insert to map
			if (first.find(",") != std::string::npos || second.find(",") != std::string::npos)
				return (row + 1);
			else if (first.empty() || second.empty())
				return (row + 1);
			else
			{
				if (row > 0)
				{
					//dbmap.insert(std::pair<std::string,std::string>(first,second));
					if (validateDate(first) && validateRate(second))
					{
						std::pair<std::map<std::string,std::string>::iterator, bool> res = dbmap.insert(std::pair<std::string,std::string>(getDate(first),second));
						if (res.second != true)
						{
							warning("insertion failed for row: " << row << " => " << line );
						}
					}
					else
						return (row + 1);
				}
			}
		}
		else
			return (row + 1);
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
		// db validation
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

bool BitcoinExchange::validateDB(void)
{
	// int line = 1;
	if (dbmap.empty())
		return (false);
	// post db validation removed
	// for (std::map<std::string,std::string>::iterator it = dbmap.begin(); it != dbmap.end(); it++)
	// {
	// 	bool date = 0;
	// 	bool val = 0;
	// 	
	// 	date = validateDate(it->first);
	// 	val = validateRate(it->second);
	// 	if (!date)
	// 		message("Invalid date on: " << line <<" :"<< it->first);
	// 	if (!val)
	// 		message("Invalid value on: " << line <<" :"<< it->second);
	// 	if (!date || !val)
	// 	{
	// 		dbmap.clear();
	// 		return (false);
	// 	}
	// }
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

/*
 outofrange true when date < database.min() || date > database.max()
*/
void BitcoinExchange::Query(std::string date, std::string amount)
{
	std::map<std::string,std::string>::iterator it = dbmap.find(date);
	bool outofrange = false;
	if (it == dbmap.end())
	{
		it = dbmap.lower_bound(date);
		if (it != dbmap.end() && it != dbmap.begin())
			it --;
		else
			outofrange = true;
	}
	//debug(it->second);
	if (!outofrange)
	{
		std::cout << date << "\t:" << amount << "\t* " \
		<< it->second << "\t=\t"\
		<<  (std::atof(amount.c_str())) * (std::atof(it->second.c_str())) << std::endl;
	}
	else
		message(date << " is out of range for the db");
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
				message("invalid date => " << first);
			// if (!amount)
			// 	message("invalid amount => " << second);
			if (date && amount)
			{
				Query(getDate(first), second);
				//Query(first, second);
			}
		}
		else
			message("wrong format => " << str);
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

