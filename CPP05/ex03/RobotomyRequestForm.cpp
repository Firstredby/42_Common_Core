#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyForm", 72, 45), target("unnamed")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if (this != &obj)
		AForm::operator=(obj);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!checkSign())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::LowGradeExecution();
	srand(std::time(0));
	if (rand() % 2)
		cout << "*Mechanical noise*\n" << this->target << "'s robotomization completed successfully!\n";
	else
		cout << "*Twisted metal noise*\n" << this->target << "'s robotomization failed.\n";
}