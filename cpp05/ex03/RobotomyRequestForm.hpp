#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
    private:
        std::string const target;
        RobotomyRequestForm();
    public:
        RobotomyRequestForm(std::string const target);
        virtual ~RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm const &o);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &o);
        std::string const getTarget() const;
        void execute(Bureaucrat const & executor) const;
};

#endif