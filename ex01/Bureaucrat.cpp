#include "Bureaucrat.hpp"

class Bureaucrat::GradeTooHighException : public std::exception
{
	public:
		const char *what() const throw()
		{
			return "GradeTooHighException: The highest grade is 1";
		}
};

class Bureaucrat::GradeTooLowException : public std::exception
{
	public:
		const char *what() const throw()
		{
			return "GradeTooLowException: The lowest grade is 150";
		}
};

Bureaucrat::Bureaucrat() {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &o)
{
	*this = o;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &o)
{
    grade = o.grade;
	return *this;
}

std::string const Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::incrementGrade()
{
	if (grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade++;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return os;
}

void Bureaucrat::signForm(Form &f) const
{
	try
	{
		f.beSigned(*this);
		std::cout << name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << name << " couldn't sign " << f.getName() << " because " << e.what() << "." << std::endl;
	}
}
