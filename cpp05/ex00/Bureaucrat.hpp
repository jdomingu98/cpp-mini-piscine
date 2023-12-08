#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
    private:
        std::string name;
        int grade;
        Bureaucrat();
    public:
        Bureaucrat(std::string name);
        ~Bureaucrat();
        Bureaucrat(Bureaucrat const &o);
        Bureaucrat &operator=(Bureaucrat const &o);
        std::string const &getName() const;
        int const &getGrade() const;
        class GradeTooHighException;
        class GradeTooLowException;
};

#endif