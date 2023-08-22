#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->_current_idx = 0;
}

PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact(Contact newContact)
{
	if (this->_current_idx == 8)
		this->_current_idx = 0;
	this->_contacts[this->_current_idx] = newContact;
	this->_current_idx++;
}

std::string	PhoneBook::truncate(std::string word)
{
	return (word.length() >= 10 ? (word.substr(0, 9) + ".") : (word));
}

void	PhoneBook::printBook()
{
	int end;

	if (this->_current_idx == 0)
		end = 7;
	else
		end = this->_current_idx - 1;
	for (int i = this->_current_idx; i != end; i++)
	{
		if (this->_contacts[i].getFirstName().compare("") != 0)
		{
			std::cout << std::setw(10) << i << "|";
			std::cout << std::setw(10) << truncate(this->_contacts[i].getFirstName()) << "|";
			std::cout << std::setw(10) << truncate(this->_contacts[i].getLastName()) << "|";
			std::cout << std::setw(10) << truncate(this->_contacts[i].getNickname()) << std::endl;
			if (i == 7)
			i = 0;
		}
	}
}

void	PhoneBook::printSelectedContact(int idx)
{
	Contact c = this->_contacts[idx];

	std::cout << "First Name: " << c.getFirstName() << std::endl;
	std::cout << "Last Name: " << c.getLastName() << std::endl;
	std::cout << "Nickname: " << c.getNickname() << std::endl;
	std::cout << "Phone Number: " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
}