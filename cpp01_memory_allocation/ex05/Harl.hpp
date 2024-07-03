#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
    public:
        Harl(void);

        void        complain(std::string level);
        size_t      getIndex(std::string level);
        std::string getLevel(size_t index);

    private:
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);

        static const std::string levels[4];
};

#endif