#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void) {
	Form f1("f1", 5, 5);
	Form f2("f2", 149, 149);

	Bureaucrat b1("Segimundo", 1);
	Bureaucrat b2("Hantonia", 150);

	b1.signForm(f1);
	b2.signForm(f2);

	return (0);
}