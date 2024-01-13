#include "AForm.hpp"

class AForm::GradeTooHighException : public std::exception
{
	public:
		const char *what() const throw()
		{
			return "the grade is too high";
		}
};

class AForm::GradeTooLowException : public std::exception
{
	public:
		const char *what() const throw()
		{
			return "the grade is too low";
		}
};

class AForm::FormNotSignedException : public std::exception
{
	public:
		const char *what() const throw()
		{
			return "the form is not signed";
		}
};

AForm::AForm() : name("noname"), isSigned(false), gradeToSign(1), gradeToExecute(1) {}

AForm::AForm(std::string const name, int const gradeToSign, int const gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(AForm const &o) : name(o.name), isSigned(o.isSigned), gradeToSign(o.gradeToSign), gradeToExecute(o.gradeToExecute)
{
	*this = o;
}

AForm &AForm::operator=(AForm const &o)
{
	isSigned = o.isSigned;
	return *this;
}

std::string const AForm::getName() const
{
	return name;
}

int AForm::getGradeToSign() const
{
	return gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

void AForm::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > gradeToSign) //140 > 25
		throw AForm::GradeTooLowException();
	else
		isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!isSigned)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > gradeToExecute)
		throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, AForm const &f)
{
	os	<< f.getName() << " form"
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to execute: " << f.getGradeToExecute()
		<< ", is signed: " << (f.getIsSigned() ? "Yes" : "No")
		<< "." << std::endl;
	return os;
}
