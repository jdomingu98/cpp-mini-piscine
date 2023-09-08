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
		bool	_circular;

	public:
		PhoneBook();
		~PhoneBook();

		bool		getCircular();
		void		setCircular(bool value);
		int			getCurrentIndex();

		void		addContact(Contact c);
		void		printBook();
		std::string	truncate(std::string word);
		void		printSelectedContact(int idx);
};

#endif