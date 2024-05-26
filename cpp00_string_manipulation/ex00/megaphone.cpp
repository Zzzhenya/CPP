#include <iostream>
#include <string>

void    shout_word(char *word, int argc, int *loc)
{
    std::string str = word;
    std::string::iterator i;
    i = str.begin();
    while (i != str.end())
    {
        std::cout << static_cast<char>(std::toupper(*i));
        i ++;
    }
    *loc += 1;
    if (*loc < argc)
        std::cout << ' ';
}

int main(int argc, char **argv)
{
    int loc;

    loc = 1;
    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        argv ++;
        while (*argv)
        {
            shout_word(*argv, argc, &loc);
            argv ++;
        }
        std::cout << std::endl;
    }
    return (0);
}