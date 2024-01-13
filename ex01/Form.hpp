#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const name;
		bool isSigned;
		int const gradeToSign;
		int const gradeToExecute;
		Form();
	public:
		Form(std::string const name, int const gradeToSign, int const gradeToExecute);
		~Form();
		Form(Form const &o);
		Form &operator=(Form const &o);
		std::string const getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool getIsSigned() const;
		class GradeTooHighException;
		class GradeTooLowException;
		void beSigned(Bureaucrat const &b);
};

std::ostream &operator<<(std::ostream &os, Form const &f);

#endif
