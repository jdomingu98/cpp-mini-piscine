#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("noname", 72, 45), target("notarget") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &o) : AForm(o), target(o.target)
{
    *this = o;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &o)
{
    (void) o;
    return *this;
}

std::string const RobotomyRequestForm::getTarget() const
{
    return target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor);
    std::srand(time(NULL));
    std::cout << "* drilling noises *" << std::endl;
    if (std::rand() % 2)
        std::cout << target << " has been robotomized successfully" << std::endl;
    else
        std::cout << target << " robotomization failed" << std::endl;
}