#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

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
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b);

#endif