#include <iostream>
#include <string>

void    shout_word(char *word)
{
    std::string str (word);
    std::string::iterator i (str.begin());
    while (i != str.end())
    {
        *i = std::toupper(*i);
        i ++;
    }
    std::cout << str;
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
            shout_word(*argv);
            loc += 1;
            if (loc < argc)
                std::cout << ' ';
            argv ++;
        }
        std::cout << std::endl;
    }
    return (0);
}