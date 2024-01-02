#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {
	Bureaucrat b1("Pepe", 5);
	Bureaucrat b2("Manolo", 140);
	Bureaucrat b3("Antonio", 100);
	Bureaucrat b4("Paco", 150);

	AForm *form;
	Intern i = Intern();

	form = i.makeForm("shrubbery", "file");
	if (!form)
		return (1);

	try {
		form->beSigned(b4);
	} catch (std::exception &e) {
		std::cout << "shrubbery could not be signed because " << e.what() << std::endl;
	}

	try {
		b4.executeForm(*form);
	} catch (std::exception &e) {
		std::cout << "shrubbery could not be executed because " << e.what() << std::endl;
	}

	delete form;

	//----------------------------------------------------------------------------------

	form = i.makeForm("robotomy", "Paco");
	if (!form)
		return (1);
	try {
		form->beSigned(b1);
	} catch (std::exception &e) {
		std::cout << "robotomy could not be signed because " << e.what() << std::endl;
	}

	try {
		b1.executeForm(*form);
	} catch (std::exception &e) {
		std::cout << "robotomy could not be executed because " << e.what() << std::endl;
	}

	delete form;

	//----------------------------------------------------------------------------------

	form = i.makeForm("pardon", "Paco");
	if (!form)
		return (1);
	try {
		form->beSigned(b1);
	} catch (std::exception &e) {
		std::cout << "pardon could not be signed because " << e.what() << std::endl;
	}

	try {
		b1.executeForm(*form);
	} catch (std::exception &e) {
		std::cout << "pardon could not be executed because " << e.what() << std::endl;
	}

	delete form;

	//----------------------------------------------------------------------------------

	form = i.makeForm("form42", "cpp-moulinette");
	if (!form)
	{
		std::cout << "form42 could not be created" << std::endl;
		return (0);
	}
	delete form;

	//----------------------------------------------------------------------------------

	return (0);
}