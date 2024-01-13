#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string const target;
        ShrubberyCreationForm();
    public:
        ShrubberyCreationForm(std::string const target);
        virtual ~ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm const &o);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &o);
        std::string const getTarget() const;
        void execute(Bureaucrat const & executor) const;
};

#endif