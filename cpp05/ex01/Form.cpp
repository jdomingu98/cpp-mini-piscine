#include "Form.hpp"

Form::Form() : name("noname"), isSigned(false), gradeToSign(1), gradeToExecute(1) {}

Form::Form(std::string const name, int const gradeToSign, int const gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::~Form() {}

Form::Form(Form const &o) : name(o.name), gradeToSign(o.gradeToSign), gradeToExecute(o.gradeToExecute), isSigned(o.isSigned)
{
	*this = o;
}

Form &Form::operator=(Form const &o)
{
	isSigned = o.isSigned;
	return *this;
}

std::string const Form::getName() const
{
	return name;
}

int Form::getGradeToSign() const
{
	return gradeToSign;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

class Form::GradeTooHighException : public std::exception
{
	public:
		const char *what() const throw()
		{
			return "GradeTooHighException: The highest grade is 1";
		}
};

class Form::GradeTooLowException : public std::exception
{
	public:
		const char *what() const throw()
		{
			return "GradeTooLowException: The lowest grade is 150";
		}
};

void Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > gradeToSign)
		throw Form::GradeTooLowException();
	else
		isSigned = true;
}

std::ostream &operator<<(std::ostream &os, Form const &f)
{
	os << f.getName() << " form, grade to sign: " << f.getGradeToSign() << ", grade to execute: " << f.getGradeToExecute() << ", is signed: " << f.getIsSigned() << std::endl;
	return os;
}
