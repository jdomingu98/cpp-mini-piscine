#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &o)
{
	*this = o;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &o)
{
	name = o.name;
    grade = o.grade;
	return *this;
}

