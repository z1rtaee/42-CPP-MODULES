#include "PhoneBook.hpp"

command get_command(const std::string &input)
{
    if (input == "ADD")
        return ADD;
    else if (input == "SEARCH")
        return SEARCH;
    else if (input == "EXIT")
        return EXIT;
    else
        return IGNORE;
}

int main()
{
    PhoneBook phonebook;
    std::string input;
    //Internally, std::string often looks something like:
    //class string {
    //char* data;
    //size_t size;
    //size_t capacity;
    //};

    std::cout << "Welcome to your \e[0;95mphonebook!\e[0m" << std::endl;
    usleep(2000000);
    std::cout << "Available commands: \e[1;37mADD\e[0m, \e[1;37mSEARCH\e[0m, \e[1;37mEXIT\e[0m" << std::endl;
    std::cout << "The commands are case-sensitive." << std::endl;
    usleep(2000000);
    while (true)
    {
        std::cout << "Enter a command: ";
        if (!std::getline(std::cin, input))
            break;
        switch (get_command(input))
        {
            case ADD:
                std::cout << "\e[1;35mAdding a new contact...\e[0m" << std::endl;
                phonebook.add_contact();
                break;
            case SEARCH:
                std::cout << "\e[1;35mSearching for a contact...\e[0m" << std::endl;
                phonebook.search_contact();
                break;
            case EXIT:
                return (0);
            case IGNORE:
                break;
        }
    }
    return (0);
}
