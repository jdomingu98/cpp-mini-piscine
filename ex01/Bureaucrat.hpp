#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        std::string const name;
        int grade;
        Bureaucrat();
    public:
        class GradeTooHighException;
        class GradeTooLowException;
        Bureaucrat(std::string const name, int grade);
        ~Bureaucrat();
        Bureaucrat(Bureaucrat const &o);
        Bureaucrat &operator=(Bureaucrat const &o);
        std::string const getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(Form &f) const;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b);

#endif