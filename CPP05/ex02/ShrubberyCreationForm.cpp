#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyForm", 145, 137), target("unnamed")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	if (this != &obj)
		AForm::operator=(obj);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!checkSign())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::LowGradeExecution();
	std::string fileName = executor.getName() + "_shrubbery";
	std::ofstream newFile(fileName.data());
	newFile << "              v .   ._, |_  .,\n"
    << "           `-._\\/  .  \\ /    |/_\n"
    << "               \\\\  _\\, y | \\//\n"
    << "         _\\_.___\\\\, \\\\/ -.\\||\n"
    << "           `7-,--.`._||  / / ,\n"
    << "           /'     `-. `./ / |/_.\'\n"
    << "                     |    |//\n"
    << "                     |_    /\n"
    << "                     |-   |\n"
    << "                     |   =|\n"
    << "                     |    |\n"
    << "--------------------/ ,  . \\--------._\n";
	newFile.close();
}