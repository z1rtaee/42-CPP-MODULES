#include  "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contact_count(0), _oldest_contact_index(0){}
//INITIALIZATION LIST -> :
//DIFERENÇA DESTE PARA O DEBAIXO -> aqui quando esta a criar o objeto ja diz que valores cada atributo vai ter entao quandoi o objeto e criado ja tem valor
//Por isso se fosse const neste caso seria possivel alterar mais tarde pq e definida ja com o valor antes da criação do objeto

//PhoneBook::PhoneBook() {
//    _contact_count = 0;
//    _oldest_contact_index = 0;
//}   

static bool is_number(const std::string& str)
{
    if (str.empty())
        return false;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

void PhoneBook::add_contact()
{
    Contact newContact;
    if (!newContact.setInfo())
    {
        std::cout << "\e[1;31mFailed to add contact. Please try again.\e[0m" << std::endl;
        return;
    }
    if (_contact_count < 8)
    {
        _contacts[_contact_count] = newContact;
        _contact_count++;
    }
    else
    {
        _contacts[_oldest_contact_index] = newContact;
        _oldest_contact_index = (_oldest_contact_index + 1) % 8;
    }
}

void PhoneBook::search_contact() const
{
    if (_contact_count == 0)
    {
        std::cout << "\e[1;31mNo contacts available. Please add a contact first.\e[0m" << std::endl;
        return;
    }

    for (int i = 0; i < _contact_count; i++)
        _contacts[i].displaySummary(i);
    std::string input; 
    std::cout << "Enter the index of the contact to view details: ";
    if (!std::getline(std::cin, input) || input.empty())
        return ;
    if (!is_number(input))
    {
        std::cout << "\e[1;31mInvalid input.\e[0m" << std::endl;
        return;
    }
    
    int index = atoi(input.c_str());
    if (index < 0 || index >= _contact_count)
    {
        std::cout << "\e[1;31mInvalid contact index.\e[0m" << std::endl;
        return;
    }
    _contacts[index].displayDetails();
}