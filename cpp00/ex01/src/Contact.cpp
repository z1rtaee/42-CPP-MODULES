#include "Contact.hpp"

Contact::Contact() : _firstName(""), _lastName(""), _nickname(""), _phoneNumber(""), _darkestSecret("") {}

static bool is_phone_number(std::string& phone_number)
{
    if (phone_number.empty())
        return false;

    for (size_t i = 0; i < phone_number.length(); i++)
    {
        if (!i && phone_number[i] == '+' && phone_number.length() > 1)
            continue;
        if (!isdigit(phone_number[i]))

            return false;
    }
    return true;
}

std::string formatField(const std::string& str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

bool Contact::setInfo()
{
    while (true)
    {
        std::cout << "First name: ";
        if (!std::getline(std::cin, _firstName))
            return false; 
        if (!_firstName.empty())
            break;
        std::cout << "\e[1;31mFirst name cannot be empty. Please try again.\e[0m" << std::endl;
    }
    while (true)
    {
        std::cout << "Last name: ";
        if (!std::getline(std::cin, _lastName))
            return false;
        if (!_lastName.empty())
            break;
        std::cout << "\e[1;31mLast name cannot be empty. Please try again.\e[0m" << std::endl;
    }
    while (true)
    {
        std::cout << "Nickname: ";
        if (!std::getline(std::cin, _nickname))
            return false; 
        if (!_nickname.empty())
            break;
        std::cout << "\e[1;31mNickname cannot be empty. Please try again.\e[0m" << std::endl;
    }
    while (true)
    {
        std::cout << "Phone number: ";
        if (!std::getline(std::cin, _phoneNumber))
            return false; 
        if (!_phoneNumber.empty() && is_phone_number(_phoneNumber))
            break;
        if (_phoneNumber.empty())
            std::cout << "\e[1;31mPhone number cannot be empty. Please try again.\e[0m" << std::endl;
        else
            std::cout << "\e[1;31mInvalid phone number format. Please try again.\e[0m" << std::endl;
    }
    while (true)
    {
        std::cout << "Darkest secret: ";
        if (!std::getline(std::cin, _darkestSecret))
            return false; 
        if (!_darkestSecret.empty())
            break;
        std::cout << "\e[1;31mDarkest secret cannot be empty. Please try again.\e[0m" << std::endl;
    }
    return true;
}

void Contact::displaySummary(int index) const
{
    std::cout << std::setw(10) << index << "|"
              << std::setw(10) << formatField(_firstName) << "|"
              << std::setw(10) << formatField(_lastName) << "|"
              << std::setw(10) << formatField(_nickname)
              << std::endl;
}


void Contact::displayDetails() const
{
    std::cout << "First name: " << _firstName << std::endl;
    std::cout << "Last name: " << _lastName << std::endl;
    std::cout << "Nickname: " << _nickname << std::endl;
    std::cout << "Phone number: " << _phoneNumber << std::endl;
    std::cout << "Darkest secret: " << _darkestSecret << std::endl;
}