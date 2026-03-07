#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <unistd.h>
# include <iomanip>
# include <string>
# include <cctype>
# include <cstdlib>

class Contact {
    public:
        Contact();
        bool setInfo();

        void displaySummary(int index) const;
        void displayDetails() const;

    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;
};


#endif