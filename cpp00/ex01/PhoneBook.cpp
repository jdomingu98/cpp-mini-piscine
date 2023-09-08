#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->_first_idx = 0;
	this->_current_idx = 0;
	this->_circular = false;
}

PhoneBook::~PhoneBook() {}

bool	PhoneBook::getCircular()
{
	return this->_circular;
}

void	PhoneBook::setCircular(bool value)
{
	this->_circular = value;
}

int	PhoneBook::getCurrentIndex()
{
	return this->_current_idx;
}

void	PhoneBook::addContact(Contact newContact)
{
	this->_contacts[this->_current_idx] = newContact;
	this->_current_idx++;
	if (this->_current_idx == 8)
	{
		this->_current_idx = 0;
		this->_circular = true;
	}
	if (this->_current_idx == this->_first_idx)
		this->_first_idx = this->_current_idx + 1;
	if (this->_first_idx == 8)
		this->_first_idx = 0;
}

std::string	PhoneBook::truncate(std::string word)
{
	return (word.length() >= 10 ? word.substr(0, 9) + "." : word);
}

void	PhoneBook::printBook()
{
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "Name" << "|";
	std::cout << std::setw(10) << "LastName" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	for(int i = 0; i < 8; i++)
	{
		if(!(!getCircular() && i > getCurrentIndex() - 1))
		{
			std::cout << std::setw(10) << i << "|";
			std::cout << std::setw(10) << truncate(this->_contacts[i].getFirstName()) << "|";
			std::cout << std::setw(10) << truncate(this->_contacts[i].getLastName()) << "|";
			std::cout << std::setw(10) << truncate(this->_contacts[i].getNickname()) << "|" << std::endl;
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