#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
	Bureaucrat b1("Pepe", 5);
	Bureaucrat b2("Alesito", 140);
	Bureaucrat b3("Antonio", 100);
	Bureaucrat b4("Juan", 150);

	ShrubberyCreationForm s1("trees");
	RobotomyRequestForm r1("robotomy");
	PresidentialPardonForm p1("The Pope");

	try {
		s1.beSigned(b4);
	} catch (std::exception &e) {
		std::cout << s1.getTarget() << " could not be signed because " << e.what() << std::endl;
	}

	try {
		b4.executeForm(s1);
	} catch (std::exception &e) {
		std::cout << s1.getTarget() << " could not be signed because " << e.what() << std::endl;
	}

	try {
		r1.beSigned(b1);
	} catch (std::exception &e) {
		std::cout << r1.getTarget() << " could not be signed because " << e.what() << std::endl;
	}

	try {
		b1.executeForm(r1);
	} catch (std::exception &e) {
		std::cout << r1.getTarget() << " could not be signed because " << e.what() << std::endl;
	}

	try {
		p1.beSigned(b2);
	} catch (std::exception &e) {
		std::cout << p1.getTarget() << " could not be signed because " << e.what() << std::endl;
	}

	try {
		b2.executeForm(p1);
	} catch (std::exception &e) {
		std::cout << p1.getTarget() << " could not be signed because " << e.what() << std::endl;
	}

	return (0);
}