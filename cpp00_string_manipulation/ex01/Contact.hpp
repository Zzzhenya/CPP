#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
    public:
        Contact(void);
        ~Contact(void);
        Contact(std::string c_first_name, std::string c_last_name,
            std::string c_nickname, std::string c_phone_number,
            std::string c_darkest_secret);
        // Contact(std::string c_name, std::string c_lname, std::string c_num);
        std::string getname(void);
        std::string getlast_name(void);
        std::string getphone_number(void);
        std::string getnickname(void);
        std::string getsecret(void);
    private:
        std::string first_name;
        std::string last_name;
        std::string phone_number;
        std::string nickname;
        std::string darkest_secret;
};

#endif