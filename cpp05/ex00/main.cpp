#include "Bureaucrat.hpp"

int	main(void) {

	Bureaucrat b1("Juan Antonio", 149);
	std::cout << "1: " << b1;

	try {
		b1.decrementGrade();
		std::cout << "2: " << b1;
		b1.decrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "3: " << b1;

	try {
		Bureaucrat b2("Alex", 151);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}