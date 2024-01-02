#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("noname", 25, 5), target("notarget") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &o) : AForm(o), target(o.target)
{
    *this = o;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &o)
{
    return *this;
}

std::string const PresidentialPardonForm::getTarget() const
{
    return target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor);
    std::cout << target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}