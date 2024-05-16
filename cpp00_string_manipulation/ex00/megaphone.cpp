#include <iostream>

char *shout(char *str)
{
    int i = 0;

    while (str[i])
    {
        str[i] = toupper(str[i]);
        i ++;
    }
    return (str);
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        (void)argv;
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (0);
    }
    argv++;
    while (*argv)
    {
        *argv = shout(*argv);
        std::cout << *argv;
        argv++;
        if (*argv)
            std::cout << " ";
    }
    std::cout << "\n"; 
    return (0);
}