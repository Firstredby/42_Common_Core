#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	cout << "Default constructor called!\n";
}

Intern::Intern(const Intern& obj)
{
	(void)obj;
	cout << "Default copy constructor called!\n";
}

Intern& Intern::operator=(const Intern& obj)
{
	cout << "Default copy assignment constructor called!\n";
	if (this != &obj)
		*this = obj;
	return *this;
}

Intern::~Intern()
{
	cout << "Default destructor called!\n";
}

AForm * Intern::createPP(const std::string& target) const
{
	cout << "Intern creates PresidentialPardonForm!\n";
	return new PresidentialPardonForm(target);
}

AForm * Intern::createRR(const std::string& target) const
{
	cout << "Intern creates RobotomyRequestForm!\n";
	return new RobotomyRequestForm(target);
}

AForm * Intern::createSC(const std::string& target) const
{
	cout << "Intern creates ShrubberyCreationForm!\n";
	return new ShrubberyCreationForm(target);
}

AForm * Intern::notExists(const std::string& target) const
{
	std::cerr << "Form " << target << " does not exists!\n";
	return NULL;
}

AForm*	Intern::makeForm(const std::string& name,
		const std::string& target) const
{
	formList table[] = {
		{"shrubbery creation", &Intern::createSC},
		{"presidential pardon", &Intern::createPP},
		{"robotomy request", &Intern::createRR}
	};
	size_t size = 0;
	while (size != 3 && table[size].name != name)
		size++;
	if (size == 3)
		return Intern::notExists(target);
	return (this->*table[size].type)(target);
}