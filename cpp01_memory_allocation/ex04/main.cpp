/*

Create a program that takes three parameters in the following order: a filename and
two strings, s1 and s2.
	filename s1 s2

It will open the file <filename> and copies its content into a new file
<filename>.replace, replacing every occurrence of s1 with s2.

Using C file manipulation functions is forbidden and will be considered cheating. All
the member functions of the class std::string are allowed, except replace. Use them
wisely!
Of course, handle unexpected inputs and errors. You have to create and turn in your
own tests to ensure your program works as expected.

Forbidden functions : std::string::replace

*/

#include <iostream>
#include <fstream>
#include <string>

int	has_needle(std::string haystack, std::string needle)
{
	size_t loc = haystack.find(needle);

	if (loc != std::string::npos)
		return (1);
	else
		return (0);
}

std::string	replace_needle(std::string line, std::string s1, std::string s2)
{
	size_t loc = line.find(s1);

	while (loc != std::string::npos)
	{
		line.erase(	loc, s1.length());
		line.insert(loc, s2);
		loc = line.find(s1, loc + 1);
	}
	return (line);
}


int	openfile_and_read(char *filename, char *find, char *replace)
{
	std::fstream 	s(filename, std::ios::in);
	std::string 	line;
	std::string 	outfile_name

	if (!s.is_open())
	{
		std::cerr << "Failed to open file " << filename << std::endl;
		return (0);
	}
	else
	{
		outfile_name = std::string(filename) + std::string(".replace");
		std::fstream outfile((const char *)outfile_name.c_str(), std::ios::out | std::ios::trunc);
		if (!outfile.is_open())
		{
			std::cerr << "failed to create " << outfile_name.c_str() << "\n";
			s.close();
			return (0);	
		}
		while (1)	
		{
			std::getline(s, line);
			if (s.eof())
				break;
			if (has_needle(line, find))
				line = replace_needle(line, find, replace);
			outfile << line << "\n";
		}
		s.close();
		outfile.close();
	}
	return (1);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Wrong arg count." << std::endl;
		std::cerr << "Usage: filename \"Search word\" \"replacement word\"" << std::endl;
		return (1);
	}
	if (std::string(argv[2]).length() == 0)
	{
		std::cerr << "Search word is empty." << std::endl;
		return (1);
	}
	if (!openfile_and_read(argv[1], argv[2], argv[3]))
		return (1);
	return (0);
}