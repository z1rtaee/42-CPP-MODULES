#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

enum command
{
    ADD,
    SEARCH,
    EXIT,
	IGNORE
};

class	PhoneBook {
	public:
		PhoneBook(); //default constructor

		void	add_contact();
		void	search_contact() const;

	private:
		Contact _contacts[8];
		
		int _contact_count;
		int _oldest_contact_index;
		//private variables usally have _ before
};

#endif