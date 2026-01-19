#pragma once

#include "Bureaucrat.hpp"

class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern
{
private:
	typedef AForm*	(Intern::*form)(const std::string&) const;
	Intern(const Intern&);
	typedef struct 
	{
		std::string name;
		form type;
	} formList;
public:
	Intern();
	Intern& operator=(const Intern&);
	~Intern();

	AForm*	makeForm(const std::string&, const std::string&) const;
	AForm* createPP(const std::string& target) const;
	AForm* createRR(const std::string& target) const;
	AForm* createSC(const std::string& target) const;
	AForm* notExists(const std::string& target) const;
};

