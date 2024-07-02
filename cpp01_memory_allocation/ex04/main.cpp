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

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Worng arg count" << std::endl;
		return (0);
	}
	std::string filename(argv[1]);
	//std::fstream s;

	std::fstream s(filename,std::ios::in);
	std::cout << "Filename: " << filename << std::endl;
	std::cout << "Replace " << argv[2] ;
	std::cout << " with " << argv[3] << std::endl;
	std::string line;
	if (!s.is_open())
		std::cout << "failed to open " << filename << "\n";
	else
	{
		while(1)
		{
			std::getline(s, line);
			if (s.eof())
				break;
			//if (!line.empty())
			std::cout << line <<"\n";
			//else
			//	break;
		}
	}
	// std::ifstream fin(filename);
	return (0);
}