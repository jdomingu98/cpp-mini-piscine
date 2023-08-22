#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _contacts[8];
		int		_first_idx;
		int     _current_idx;

	public:
		PhoneBook();
		~PhoneBook();

		void		addContact(Contact c);
		void		printBook();
		std::string	truncate(std::string word);
		void		printSelectedContact(int idx);
};

#endif