#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("noname", 145, 137), target("notarget") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &o) : AForm(o), target(o.target)
{
    *this = o;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &o)
{
    return *this;
}

std::string const ShrubberyCreationForm::getTarget() const
{
    return target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::ofstream outfile;
    AForm::execute(executor);
    
    outfile.open((target + "_shrubbery").c_str());

    if (!outfile.is_open())
    {
        std::cout << "Error: could not open file" << std::endl;
        return ;
    }
    
    outfile << "      /\\\n"
            << "     /\\*\\\n"
            << "    /\\O\\*\\\n"
            << "   /*/\\/\\/\\\n"
            << "  /\\O\\/\\*\\/\\\n"
            << " /\\*\\/\\*\\/\\/\\\n"
            << "/\\O\\/\\/*/\\/O/\\\n"
            << "      ||\n"
            << "      ||\n"
            << "      ||\n"
            << "    \\====/\n"
            << "     \\__/  hjw\n";
    
    outfile.close();
}