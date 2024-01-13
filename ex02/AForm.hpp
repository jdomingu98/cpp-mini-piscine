#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const name;
		bool isSigned;
		int const gradeToSign;
		int const gradeToExecute;
		AForm();
	public:
		AForm(std::string const name, int const gradeToSign, int const gradeToExecute);
		virtual ~AForm();
		AForm(AForm const &o);
		AForm &operator=(AForm const &o);
		std::string const getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool getIsSigned() const;
		class GradeTooHighException;
		class GradeTooLowException;
		class FormNotSignedException;
		void beSigned(Bureaucrat const &b);
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, AForm const &f);

#endif
