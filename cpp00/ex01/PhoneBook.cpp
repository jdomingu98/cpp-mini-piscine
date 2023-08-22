#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->_first_idx = 0;
	this->_current_idx = 0;
}

PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact(Contact newContact)
{
	this->_contacts[this->_current_idx] = newContact;
	this->_current_idx++;
	if (this->_current_idx == 8)
		this->_current_idx = 0;
	if (this->_current_idx == this->_first_idx)
		this->_first_idx = this->_current_idx + 1;
	if (this->_first_idx == 8)
		this->_first_idx = 0;
	std::cout << this->_first_idx << " " << this->_current_idx << std::endl;
}

std::string	PhoneBook::truncate(std::string word)
{
	return (word.length() >= 10 ? word.substr(0, 9) + "." : word);
}

void	PhoneBook::printBook()
{
	int i = this->_first_idx - 1;

	while (++i != this->_current_idx)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncate(this->_contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << truncate(this->_contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << truncate(this->_contacts[i].getNickname()) << std::endl;
		i == 7 ? i = -1 : i;
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