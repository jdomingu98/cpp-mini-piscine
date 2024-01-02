#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(Intern const &o)
{
    *this = o;
}

Intern &Intern::operator=(Intern const &o)
{
    (void) o;
    return *this;
}

AForm *Intern::makeForm(std::string const &name, std::string const &target)
{
    AForm *form = NULL;
    std::string forms[] = { "shrubbery", "robotomy", "pardon" };
    int i;

	for (i = 0; i < forms->length(); i++) {
		if (name.find(forms[i]) != std::string::npos) {
			break ;
		}
	}

    switch (i)
    {
        case 0:
            form = new ShrubberyCreationForm(target);
			break;
        case 1:
            form = new RobotomyRequestForm(target);
			break;
        case 2:
            form = new PresidentialPardonForm(target);
			break;
        default:
            std::cout << "Intern could not create form because it does not exist" << std::endl;
            break;
    }

    if (i < 3)
        std::cout << "Intern creates " << name << " form" << std::endl;
    return form;
}