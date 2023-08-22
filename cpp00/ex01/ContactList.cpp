#include "PhoneBook.hpp"

Contact contactForm()
{
    Contact c = Contact();
    std::string info;

    std::cout << "Write the contact's first name: ";
    std::cin >> info;
    std::cout << std::endl;
    c.setFirstName(info);

    std::cout << "Write the contact's last name: ";
    std::cin >> info;
    std::cout << std::endl;
    c.setLastName(info);

    std::cout << "Write the contact's nickname: ";
    std::cin >> info;
    std::cout << std::endl;
    c.setNickname(info);

    std::cout << "Write the contact's phone number: ";
    std::cin >> info;
    std::cout << std::endl;
    c.setPhoneNumber(info);

    std::cout << "Write the contact's darkest secret: ";
    std::cin >> info;
    std::cout << std::endl;
    c.setDarkestSecret(info);

    return (c);
}

int main(void)
{
    PhoneBook   phoneBook = PhoneBook();
    std::string command = "";
    Contact     contact;
    int         i;

    while (command.compare("EXIT") != 0)
    {
        std::cout << "Write a command (ADD/ SEARCH/ EXIT):" << std::endl; 
        std::cin >> command;
        for (unsigned long i = 0; i < command.length(); i++)
            command[i] = char(toupper(command[i]));
        if (command.compare("ADD") == 0)
        {
            std::cout << "You are now in addition mode. Now give the following contact info:" << std::endl;
            contact = contactForm();
            phoneBook.addContact(contact);
            std::cout << "Contact added!" << std::endl;
        }
        else if (command.compare("SEARCH") == 0)
        {
            phoneBook.printBook();
            std::cout << "You are now in search mode. Write a valid Phonebook index:" << std::endl;
            std::cin >> i;
            if (i < 0 || i > 7)
                std::cout << "Wrong index. Exiting search mode..." << std::endl;
            else
            {
                std::cout << "Here is your contact:" << std::endl;
                phoneBook.printSelectedContact(i);
            }
        }
        else if (command.compare("EXIT") != 0)
            std::cout << "Wrong command! Valid options are: ADD / SEARCH / EXIT" << std::endl;
    }
    std::cout << "Exiting..." << std::endl;
    return (0);
}
