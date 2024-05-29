#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
    public:
        Contact(void);
        ~Contact(void);
        Contact(std::string c_name);
        std::string getName(void);
    private:
        std::string name;
};

#endif