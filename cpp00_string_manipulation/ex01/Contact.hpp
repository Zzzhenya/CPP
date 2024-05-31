#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
    public:
        Contact(void);
        ~Contact(void);
        Contact(std::string c_name, std::string c_lname, std::string c_num);
        std::string getname(void);
        std::string getlast_name(void);
        std::string getphone_number(void);
    private:
        std::string name;
        std::string last_name;
        std::string phone_number;
};

#endif